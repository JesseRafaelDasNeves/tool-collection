<?php

/**
 * Realiza require de arquivos de forma automática.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   03/05/2017
 */
class FactoryFileAutoLoadClass {

    const TYPE_CLASS     = 1,
          TYPE_NAMESPACE = 2;

    const EXTENSION_FILE_PHP_DEFAULT = 'php',
          EXTENSION_FILE_PHP_INC     = 'inc';

    private $className;
    private $fileWithPath;
    private $baseDirectory;
    private $directoryLevels;
    private $aDirectory;
    private $type;
    private $extension;

    public function __construct(string $className) {
        $this->className       = $className;
        $this->fileWithPath    = '';
        $this->baseDirectory   = '';
        $this->directoryLevels = 1;
        $this->type            = self::TYPE_CLASS;
        $this->aDirectory      = Array();
        $this->extension       = self::EXTENSION_FILE_PHP_DEFAULT;
        $this->requireDependentFiles();
    }

    public final function setBaseDirectory(string $name) {
        $this->baseDirectory = $name;
    }

    public final function getBaseDirectory() : string {
        return $this->baseDirectory;
    }

    public final function addDirectory(string $nameDirectory) {
        $this->aDirectory[] = $nameDirectory;
    }

    public function setDirectoryLevels($directoryLevels) {
        $this->directoryLevels = $directoryLevels;
    }

    public function getDirectoryLevels() {
        return $this->directoryLevels;
    }

    public final function toExtensionDefault() {
        $this->extension = self::EXTENSION_FILE_PHP_DEFAULT;
    }

    public final function toExtensionInc() {
        $this->extension = self::EXTENSION_FILE_PHP_INC;
    }

    private function loadFileNameWithPath() {
        $this->defineType();
        $oClassParse = $this->getInstanceParse();
        $oClassParse->setBaseDirectory($this->getParentDirectoryNameComplete());
        $oClassParse->setSeparator(ClassParseBase::BACKSLASH_SEPARATOR);
        $oClassParse->setDirectory($this->aDirectory);

        $this->fileWithPath = $oClassParse->toFileNameWithPath();
    }

    /**
     * @return \NamespaceParse|\ClassParse
     */
    private function getInstanceParse() {
        switch ($this->type) {
            case self::TYPE_CLASS;
                return new ClassParse($this->className);;

            case self::TYPE_NAMESPACE;
                return new NamespaceParse($this->className);
        }
    }

    /**
     * Retorne o diretório em o projeto é encontrado
     *
     * @return string
     */
    public final function getParentDirectoryName() : string {
        return dirname(__FILE__, $this->directoryLevels);
    }

    public final function getParentDirectoryNameComplete() : string {
        return $this->getParentDirectoryName() . ClassParseBase::BACKSLASH_SEPARATOR . $this->baseDirectory;
    }

    private function loadFileNameExtencion() {
        $this->fileWithPath .= '.' . $this->extension;
    }

    private function validateFileExists() {
        if(!$this->isFileExists()) {
            throw new ExceptionRequireFile("Arquivo $this->fileWithPath não existe");
        }
    }

    private function requireDependentFiles() {
        $sPath = dirname(__FILE__);
        require_once $sPath . '\class_parse_base.php';
        require_once $sPath . '\namespace_parse.php';
        require_once $sPath . '\class_parse.php';
    }

    public final function isFileExists() {
        return file_exists($this->fileWithPath);
    }

    private function defineType() {
        //Caso tiver barra invertida no nome da classe então é certeza que temos um namespace.
        $bNamespace = stripos($this->className, '\\') !== false;
        $this->type = $bNamespace ? self::TYPE_NAMESPACE : self::TYPE_CLASS;
    }

    private function loadNameFile() {
        $this->loadFileNameWithPath();
        $this->loadFileNameExtencion();
    }

    private function invokeRequireFile() {
        require_once $this->fileWithPath;
    }

    public final function requireFile() {
        $this->loadNameFile();
        $this->validateFileExists();
        $this->invokeRequireFile();
    }

    public final function requireFileIfExists() {
        $this->loadNameFile();
        if($this->isFileExists()) {
            $this->invokeRequireFile();
        }
    }

}