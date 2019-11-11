<?php

/**
 * Lê configurações.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   21/08/2017
 */
final class ReaderSettingsObjectType {

    private $fileName;
    private $Object;
    private $aData;

    public function __construct($object) {
        $this->aData  = Array();
        $this->Object = $object;
    }

    private function setFileNameByObject() {
        $this->fileName = 'settings_' . strtolower(get_class($this->Object)) . FileUtils::EXT_SETTINGS;
    }

    private function readsFile() {
        $this->aData = parse_ini_file($this->getPath(), true);
    }

    private function getPath() {
        return FileUtils::DIR_SETTINGS . '/' . $this->fileName;
    }

    private function valida() {
        if(!file_exists($this->getPath())) {
            throw new Exception("Arquivo de configuração " . $this->fileName . " não existe.");
        }
    }

    private function setDataForObject() {
        BeanUtils::callSetterByPathArray($this->Object, $this->aData, Bean::E_OFF);
    }

    public function read() {
        $this->setFileNameByObject();
        $this->valida();
        $this->readsFile();
        $this->setDataForObject();
    }
}