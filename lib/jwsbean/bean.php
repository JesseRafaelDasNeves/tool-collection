<?php

/**
 * Bean do objeto.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   19/05/2017
 */
final class Bean {

    //Constantes dos erros disparados.
    CONST E_OFF = 0,
          E_ALL = 1;

    private $Object;
    private $path;
    private $typeError;
    private $type;

    /** @var BeanMethod[] */
    private $methods;

    public function __construct($oObject, string $sPath, $params = null, $sType = BeanMethod::TIPO_GETTER) {
        $this->Object     = $oObject;
        $this->path       = $sPath;
        $this->type       = $sType;
        $this->methods    = Array();
        $this->typeError  = self::E_ALL;
        $this->validObject();
        $this->criaMethodsByPath($params);
    }

    public function getObject() {
        return $this->Object;
    }

    public function getPath() : string {
        return $this->path;
    }

    public function setTypeError($typeError) {
        $this->typeError = $typeError;
    }

    public function getTypeError() {
        return $this->typeError;
    }

    private function validObject() {
        if(!is_object($this->Object)) {
            throw new Exception("Não foi passado um objeto para o bean.");
        }
    }

    private function validMethod($oObject, $sMethod) {
        //Se pode ser chamado.
        if(is_callable([$oObject, $sMethod])) {
            return;
        }

        $oReflectionClass  = new ReflectionClass($oObject);
        $oReflectionMethod = $oReflectionClass->getMethod($sMethod);

        switch (true) {
            case !$oReflectionClass->hasMethod($sMethod):
                throw new Exception("Método " . $sMethod . " não existe no objeto '" . get_class($oObject) ."'.");
            case $oReflectionMethod->isPrivate():
                throw new Exception("Método " . $sMethod . " não pode ser disparado no objeto '" . get_class($oObject) ."' porque é privado.");
            case $oReflectionMethod->isProtected():
                throw new Exception("Método " . $sMethod . " não pode ser disparado no objeto '" . get_class($oObject) ."' porque é protected.");
            default :
                throw new Exception("Método " . $sMethod . " não pode ser disparado no objeto '" . get_class($oObject) ."'.");
        }
    }

    private function validCall($Object, $sNameMethod) {
        $this->validObject($Object);
        $this->validMethod($Object, $sNameMethod);
    }

    private function isMethodCallable($oObject, $sMethod) {
        //Se os erros estão desligado e não pode ser chamado.
        if(($this->typeError === self::E_OFF) && !is_callable([$oObject, $sMethod])) {
            return false;
        }

        return true;
    }

    public function call() {
        if($this->type === BeanMethod::TIPO_GETTER) {
            return $this->callGetter();
        }

        return $this->callSetter();
    }

    private function callGetter() {
        $oGetterAtual = $this->Object;
        $aMethods     = $this->getMethodsGetter();

        foreach ($aMethods as /* @var $oBeanMethod BeanMethod */ $oBeanMethod) {
            $oGetterAtual = $this->callBean($oGetterAtual, $oBeanMethod);
        }

        return $oGetterAtual;
    }

    private function callSetter() {
        $oObject     = $this->callGetter();
        $oBeanMethod = $this->methods[BeanMethod::TIPO_SETTER];
        $this->callBean($oObject, $oBeanMethod);
    }

    private function callBean($oObject, BeanMethod $oBeanMethod) {
        $sNameMethod = $oBeanMethod->getMethodName();
        if(!$this->isMethodCallable($oObject, $sNameMethod)) {
            return;
        }

        $this->validCall($oObject, $sNameMethod);

        if(is_array($oBeanMethod->getParameter())) {
            return call_user_func_array([$oObject, $sNameMethod], $oBeanMethod->getParameter());
        }

        return call_user_func([$oObject, $sNameMethod], $oBeanMethod->getParameter());
    }

    /**
     * Cria os metodos conformo o tipo do bean.
     *
     * @param string $sParams
     *
     * @return BeanMethod[]
     */
    private function criaMethodsByPath($sParams = null) {
        $aPartPath = explode('.', $this->path);

        if($this->type === BeanMethod::TIPO_SETTER) {
            $sMethodSetter = array_pop($aPartPath);
            $oMethod       = $this->getMethodByPartPath($sMethodSetter, BeanMethod::TIPO_SETTER);
            $oMethod->setParameter($sParams);
            $this->methods[BeanMethod::TIPO_SETTER] = $oMethod;
        }

        foreach ($aPartPath as $sPartMethodGetter) {
            $this->methods[] = $this->getMethodByPartPath($sPartMethodGetter, BeanMethod::TIPO_GETTER);
        }
    }

    private function getMethodByPartPath(string $sName, string $sTipo) : BeanMethod {
        return new BeanMethod($sName, $sTipo);
    }

    /**
     * @return BeanMethod[]
     */
    private function getMethodsGetter() : Array {
        $aRetorno = Array();
        foreach ($this->methods as $oBeanMethod) {
            if($oBeanMethod->isGetter()) {
                $aRetorno[] = $oBeanMethod;
            }
        }

        return $aRetorno;
    }
}

