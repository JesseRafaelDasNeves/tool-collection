<?php

/**
 * classe para fabricar namespace.
 *
 * @package structure
 * @author  Jessé Rafael das Neves
 * @since   17/10/2017
 */
class FactoryNamespace {

    private $module;
    private $class;
    private $aPath;
    private $path;
    private $pathClass;

    public function __construct(string $module, string $className) {
        $this->module = $module;
        $this->class  = $className;
        $this->begin();
    }

    private function begin() {
        $this->aPath  = Array();
        $this->addDirectory(FileUtils::getDirectoryInclude());
        $this->addDirectory($this->module);
    }

    private function addDirectory(string $directory) {
        $this->aPath[] = $directory;
    }

    private function createPath() {
        $this->path = implode(FileUtils::NAMESPACE_SEPARATOR, $this->aPath);
    }

    private function createPathWithClass() {
        $this->createPath();
        $this->pathClass = $this->path . FileUtils::NAMESPACE_SEPARATOR . $this->class;
    }

    public function load(int $typeMVC = DesignPattern::TYPE_MVC_CONTROLLER, int $context = DesignPattern::CONTEXT_CLASS) {
        $this->addDirectory(DesignPattern::getNameByType($typeMVC));
        if($context != DesignPattern::CONTEXT_CLASS) {
            $this->addDirectory(DesignPattern::getNameByContext($context));
        }
        $this->createPathWithClass();
        return $this->pathClass;
    }

    public function loadTable() {
        return $this->load(DesignPattern::TYPE_PERSISTENCE, DesignPattern::CONTEXT_TABLE);
    }
}