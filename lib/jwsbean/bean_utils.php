<?php

/**
 * Bean util para set's e get's em objetos.
 *
 * @package STC
 * @author  Jessé Rafael das Neves
 * @since   24/07/2017
 */
class BeanUtils {

    public static function callGetter($oObject, $sPath, $error = Bean::E_ALL) {
        $oBean = new Bean($oObject, $sPath);
        $oBean->setTypeError($error);

        return $oBean->call();
    }

    public static function callSetter($oObject, $sPath, $parameters, $error = Bean::E_ALL) {
        $oBean = new Bean($oObject, $sPath, $parameters, BeanMethod::TIPO_SETTER);
        $oBean->setTypeError($error);
        $oBean->call();
    }

    public static function callSetterByPathArray($oObject, Array $aPathValue, $error = Bean::E_ALL) {
        foreach ($aPathValue as $sPath => $parms) {
            self::callSetter($oObject, $sPath, $parms, $error);
        }
    }

}