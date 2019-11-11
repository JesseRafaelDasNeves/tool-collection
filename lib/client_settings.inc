<?php

/**
 * Configurações do cliente.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   18/05/2017
 */
final class ClientSettings {

    const PATH          = 'settings/',
          FILE_PRE_FIXO = 'client_settings_';

    private $file;
    private $clientName;
    private $aSettings;

    /** @var DataBase */
    private $DataBase;

    public function __construct($sClientName) {
        $this->DataBase   = new DataBase();
        $this->clientName = strtolower($sClientName);
        $this->file       = $this->getFileByClient();
        $this->settingsRead();
        $this->settingsReadDataBase();
    }

    public function getDataBase() {
        return $this->DataBase;
    }

    /**
     * Lê as configurações do cliente.
     *
     * @throws Exception
     */
    private function settingsRead() {
        $this->aSettings = parse_ini_file($this->file, true);

        if(!$this->aSettings) {
            throw new Exception('Configuração do cliente ' . $this->clientName . ' não existe.');
        }
    }

    /**
     * Lê as configurações do banco de dados.
     */
    private function settingsReadDataBase() {
        $aDataBase = $this->aSettings['DATA_BASE'];

        BeanUtils::callSetterByPathArray($this->DataBase, $aDataBase, Bean::E_OFF);
    }

    /**
     * Retorna o nome do diretório e arquivo de configuração do cliente.
     *
     * @return type
     */
    private function getFileByClient() {
        return self::PATH . self::FILE_PRE_FIXO . $this->clientName . FileUtils::EXT_SETTINGS;
    }
}