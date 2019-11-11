<?php

/**
 * Classe para tratamentos do caminho do Bean no objeto.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   31/07/2017
 */
final class BeanMethod {

    const TIPO_GETTER = 'get',
          TIPO_SETTER = 'set';

    private $name;
    private $type;
    private $parameter;

    public function __construct($sName, $sType, $params = null) {
        $this->name      = $sName;
        $this->type      = $sType;
        $this->parameter = $params;
    }

    public function setName($sNome) {
        $this->name = $sNome;
    }

    public function getName() {
        return $this->name;
    }

    public function setType($sTipo) {
        $this->type = $sTipo;
    }

    public function getType() {
        return $this->type;
    }

    public function setParameter($parameter) {
        $this->parameter = $parameter;
    }

    public function getParameter() {
        return $this->parameter;
    }

    public function isGetter() {
        return $this->type === self::TIPO_GETTER;
    }

    public function isSetter() {
        return $this->type === self::TIPO_SETTER;
    }

    public function getMethodName() {
        return $this->getType() . ucfirst($this->getName());
    }
}