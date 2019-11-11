<?php

/**
 * Classe de configuração da aplicação.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   04/05/2017
 */
final class ConfigurationApp {

    private $ExceptionUtils;

    private function getExceptionUtils() : ExceptionUtils {
        if(!isset($this->ExceptionUtils)) {
            $this->ExceptionUtils = new ExceptionUtils();
        }
        return $this->ExceptionUtils;
    }

    public function load() {
        $this->requireFilesWithoutLoadAuto();
        $this->loadFunctionAutoLoad();
        $this->loadExceptionFunction();
        $this->loadFunctionShutdown();
    }

    private function loadExceptionFunction() {
        set_exception_handler(Array($this->getExceptionUtils(), 'treatException'));
        set_error_handler(    Array($this->getExceptionUtils(), 'treatError'));
    }

    private function loadFunctionAutoLoad() {
        $oRequireAutoLoad = new RequireAutoLoadUtils();
        spl_autoload_register(Array($oRequireAutoLoad, 'autoLoadNamespace'));
        spl_autoload_register(Array($oRequireAutoLoad, 'autoLoadClass'));
        spl_autoload_register(Array($oRequireAutoLoad, 'autoLoadJwsQuery'));
        spl_autoload_register(Array($oRequireAutoLoad, 'autoLoadJwsBean'));
    }

    private function loadFunctionShutdown() {
        register_shutdown_function(Array($this, 'endExecution'));
    }

    public final function endExecution() {
        $this->getExceptionUtils()->treatExceptionEndExecutionApp();
    }

    private function requireFilesWithoutLoadAuto() {
        $sPath = dirname(__FILE__);

        require_once $sPath . '\file_utils.inc';
        require_once $sPath . '\require_auto_load_utils.inc';
        require_once $sPath . '\jwsautoload\factory_file_auto_load_class.php';
    }
}