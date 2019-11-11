<?php

/**
 * Foreign key da Tabela do banco de dados.
 *
 * @package    stc
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
final class ForeignKeyDataBase {

    private $name;
    private $tableClass;
    private $modulo;
    private $aReferences;

    public function __construct(string $modulo, string $tableClass, string $name) {
        $this->name        = $name;
        $this->tableClass  = $tableClass;
        $this->modulo      = $modulo;
        $this->aReferences = Array();
    }

    public function getName() : string {
        return $this->name;
    }

    public function getModulo() : string {
        return $this->modulo;
    }

    public function getTableClass() {
        return $this->tableClass;
    }

    public function addReference(string $nameColumn, string $nameColumnReference) {
        $this->aReferences[$nameColumn] = $nameColumnReference;
        return $this;
    }

    public function getReferences() : string {
        return $this->aReferences;
    }
}