<?php

/**
 * classe para alterar namespace.
 *
 * @package structure
 * @author  Jessé Rafael das Neves
 * @since   17/10/2017
 */
class NamespaceParse extends ClassParseBase {

    private $namespace;

    public function __construct(string $namespace) {
        parent::__construct($this->extractClass($namespace));
        $this->namespace = $namespace;
    }

    /**
     * Prepara os dados para realizar o parse.
     */
    private function loadDirectorys() {
        $aPathWithClass = explode(self::BACKSLASH_SEPARATOR, $this->namespace);
        array_pop($aPathWithClass);

        foreach ($aPathWithClass as $dir) {
            $this->addDirectory($dir);
        }
    }

    public function extractClass(string $namespace) {
        $aNamespace = explode(self::BACKSLASH_SEPARATOR, $namespace);
        return array_pop($aNamespace);
    }

    protected function beforeTofilePath() {
        parent::beforeTofilePath();
        $this->loadDirectorys();
    }

}