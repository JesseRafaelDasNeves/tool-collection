<?php

/**
 * Classe para para realizar parse de classes
 *
 * @author 06420587921
 */
abstract class ClassParseBase {

    const BACKSLASH_SEPARATOR = "\\";

    const TYPE_FILE_UPPERCASE_FIRST = 1,
          TYPE_FILE_UNDERSCORE      = 2;

    private $className;
    private $aDirectory;
    private $separator;
    private $baseDirectory;
    private $typeFileName;

    public function __construct(string $className) {
        $this->className     = $className;
        $this->aDirectory    = Array();
        $this->separator     = self::BACKSLASH_SEPARATOR;
        $this->typeFileName      = self::TYPE_FILE_UNDERSCORE;
        $this->baseDirectory = '';
    }

    public final function setSeparator(string $separator) {
        $this->separator = $separator;
    }

    public final function getSeparator() : string {
        return $this->separator;
    }

    public final function setBaseDirectory(string $baseDirectory) {
        $this->baseDirectory = $baseDirectory;
    }

    public final function getBaseDirectory() : string {
        return $this->baseDirectory;
    }

    public final function addDirectory(string $sDirectory) {
        $this->aDirectory[] = $sDirectory;
    }

    public final function setDirectory(array $directory) {
        $this->aDirectory = $directory;
    }

    protected final function getClassName() {
        return $this->className;
    }

    public final function setTypeFileName(int $typeFile) {
        assert(in_array($typeFile, [self::TYPE_FILE_UPPERCASE_FIRST, self::TYPE_FILE_UNDERSCORE]));
        $this->typeFileName = $typeFile;
    }

    protected final function getTypeFileName() {
        return $this->typeFileName;
    }

    protected final function isFileToUnderscore() : bool {
        return $this->typeFileName === self::TYPE_FILE_UNDERSCORE;
    }

    public final function toFileNameWithPath() : string {
        $this->beforeTofilePath();
        $sFileName       = $this->toFileName();
        $aPathWithFile   = array_merge([$this->getBaseDirectory()], $this->aDirectory, [$sFileName]);

        return implode($this->getSeparator(), $aPathWithFile);
    }

    public function toFileName() : string {
        return $this->isFileToUnderscore() ? $this->toUnderscore($this->className) : $this->className;
    }

    protected function beforeTofilePath() {}

    protected final function toUnderscore(string $work) : string {
        //Coincide apenas maiúsculas menos o primeiro caracter.
        $pattern  = '/\B([A-Z])/';
        $function = function($aCharacter) {
            return '_' . $aCharacter[0];
        };
        return strtolower(preg_replace_callback($pattern, $function, $work));
    }

}
