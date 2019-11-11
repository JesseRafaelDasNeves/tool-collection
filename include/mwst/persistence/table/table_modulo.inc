<?php

namespace mwst\persistence\table;

/**
 * Tabela de modulos do sistema.
 *
 * @package    mwst
 * @subpackage persistencia/table
 * @autor      Jessé Rafael das Neves
 * @since      23/10/2017
 */
class TableModulo extends \TableDataBase {

    public function getTableName(): string {
        return 'tbmodulo';
    }

    protected function createColumns() {
        $this->addNewColumn('modcodigo', \ColumnDataBase::INTEGER);
        $this->addNewColumn('modnome'  , \ColumnDataBase::CHARACTER);
        $this->addNewColumn('modativo' , \ColumnDataBase::BOOLEAN);
    }

    protected function createPrimaryKeyConstraints() {
        $this->addPrimaryKey('modcodigo');
    }

}