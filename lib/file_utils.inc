<?php

/**
 * Classe auxiliar para arquivos e diretório.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   03/05/2017
 */
class FileUtils {

    const EXT_PHP             = '.inc',
          EXT_SETTINGS        = '.ini',
          STC_MODULO          = 'stc',//structure
          STG_MODULO          = 'stg',//settings
          CLASS_SEPARATOR     = '_',
          DIR_SEPARATOR       = "\\",
          DIR_INCLUDE         = "include",
          DIR_SETTINGS        = "settings",
          DIR_LIBRARIES       = "lib",
          DIR_LIB_JWSQUERY    = "jwsquery",
          DIR_LIB_JWSBEAN     = "jwsbean",
          NAMESPACE_SEPARATOR = "\\";


    /**
     * Retorna o nome do arquivo da classe passada.
     *
     * @param string $pathClassName Nome da Classe.
     *
     * @return string
     */
    public static function getPathFileByClassName(string $pathClassName) : string {
        $oFileByClass = new FileClassParse($pathClassName);

        return $oFileByClass->getFileWithPath();
    }

    /**
     * Retorna o diretório de include dos programas.
     *
     * @return string
     */
    public static function getDirectoryInclude() : string {
        return MainInfo::getInstance()->getProject()->getDirectoryInclude();
    }

    /**
     * Retorna o diretório do projeto
     *
     * @return string
     */
    public static function getDirectoryProject() : string {
        return MainInfo::getInstance()->getProject()->getDirectory();
    }

    /**
     * Transforma o nome da classe em um nome de arquivo php.
     *
     * @return string
     */
    public static function classToFileName(string $className) : string {
        return RegularExpression::uppercaseToUnderscore($className, false);
    }

    /**
     * Retorna um arquivo da estrutura com a classe passada.
     *
     * @param string $className
     *
     * @return string
     */
    public static function classToFileNameLib(string $className) : string {
        return self::DIR_LIBRARIES . self::DIR_SEPARATOR . self::classToFileName($className);
    }
}