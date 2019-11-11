<?php

/**
 * Informações do projeto.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   16/08/2017
 */
class Project {

    /** @var DataBase */
    private $dataBase;

    private $name;
    private $directory;
    private $directoryInclude;

    public function setName(string $name) {
        $this->name = $name;
    }

    public function getName() : string {
        return $this->name;
    }

    public function setDirectory(string $directory) {
        $this->directory = $directory;
    }

    public function getDirectory() : string {
        return $this->directory;
    }

    public function setDirectoryInclude($directoryInclude) {
        $this->directoryInclude = $directoryInclude;
    }

    public function getDirectoryInclude() {
        return $this->directoryInclude;
    }

    public function setDataBase(DataBase $dataBase) {
        $this->dataBase = $dataBase;
    }

    public function getDataBase(): DataBase {
        return $this->dataBase;
    }

    public function getDirectoryAsArray() {
        return explode("\\", $this->getDirectory());
    }
}