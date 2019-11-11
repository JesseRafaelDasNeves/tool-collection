<?php

/**
 * Classe de informações principais.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   16/08/2017
 */
final class MainInfo {

    /** @var MainInfo */
    private static $INSTANCE;

    /** @var Project */
    private $Project;

    /** @var ConnectionDataBase */
    private $ConnectionDataBase;

    private function __construct() {
        $this->readSettingsProject();
    }

    public static function getInstance() : MainInfo {
        if(!isset(self::$INSTANCE)) {
            self::$INSTANCE = new MainInfo();
        }

        return self::$INSTANCE;
    }

    public function getProject(): Project {
        if(!isset($this->Project)) {
            $this->Project = new Project();
        }

        return $this->Project;
    }

    public function getConnectionDataBase() {
        if(!isset($this->ConnectionDataBase)) {
            $this->ConnectionDataBase = new ConnectionDataBase($this->getProject()->getDataBase());
        }

        return $this->ConnectionDataBase;
    }

    private function readSettingsProject() {
        $this->getProject()->setDataBase(FactoryClientSettings::load()->getDataBase());
        $this->getProject()->setDirectory(dirname(__FILE__, 2));
        (new ReaderSettingsObjectType($this->getProject()))->read();
    }
}