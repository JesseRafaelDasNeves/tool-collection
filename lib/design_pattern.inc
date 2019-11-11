<?php

/**
 * classe para realizar namespace automatico.
 *
 * @package structure
 * @author  Jessé Rafael das Neves
 * @since   17/10/2017
 */
final class DesignPattern {

    const TYPE_MVC_MODEL      = 1,
          TYPE_MVC_VIEW       = 2,
          TYPE_MVC_CONTROLLER = 3,
          TYPE_PERSISTENCE    = 4;

    const CONTEXT_CLASS     = 1,
          CONTEXT_INTERFACE = 2,
          CONTEXT_BUSINESS  = 3,
          CONTEXT_TABLE     = 4;

    public static function getNameByType(int $type) {
        switch ($type) {
            case self::TYPE_MVC_MODEL:
                return 'model';
            case self::TYPE_MVC_VIEW:
                return 'view';
            case self::TYPE_MVC_CONTROLLER:
                return 'controller';
            case self::TYPE_PERSISTENCE:
                return 'persistence';
            default:
                throw new Exception('tipo ' . $type . ' não existente.');
        }
    }

    public static function getNameByContext(int $context) {
        switch ($context) {
            case self::CONTEXT_CLASS:
                return 'classes';
            case self::CONTEXT_INTERFACE:
                return 'interfaces';
            case self::CONTEXT_BUSINESS:
                return 'business';
            case self::CONTEXT_TABLE:
                return 'table';
            default:
                throw new Exception('contexto ' . $context . ' não existente.');
        }
    }
}