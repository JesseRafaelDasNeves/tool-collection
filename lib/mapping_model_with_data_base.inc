<?php

/**
 * Maperador da Tabela do banco de dados com o modelo.
 *
 * @package    mwbc
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
final class MappingModelDataBase {

    private $nameModel;
    private $nameColumn;

    public function __construct(string $nameModel, string $nameColumn) {
        $this->nameModel  = $nameModel;
        $this->nameColumn = $nameColumn;
    }

    public function getNameModel() {
        return $this->nameModel;
    }

    public function getNameColumn() {
        return $this->nameColumn;
    }
}