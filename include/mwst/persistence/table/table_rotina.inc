<?php

namespace mwst\persistence\table;

/**
 * Classe da table ação.
 *
 * @package    mwbc
 * @subpackage persistence/table
 * @author     Jessé Rafael das Neves
 * @since      16/10/2017
 */
final class TableRotina extends \TableDataBase {

    public function getTableName(): string {
        return 'tbrotina';
    }

    protected function createColumns() {
        $this->addNewColumn('rotcodigo', \ColumnDataBase::INTEGER);
        $this->addNewColumn('rotnome'  , \ColumnDataBase::CHARACTER);
        $this->addNewColumn('rotativo' , \ColumnDataBase::BOOLEAN);
        $this->addNewColumn('modcodigo', \ColumnDataBase::INTEGER);
    }

    protected function createPrimaryKeyConstraints() {
        $this->addPrimaryKey('rotcodigo');
    }

    protected function createForeignKeyConstraints() {
        $this->addForeignKey('MWST', 'Modulo')
             ->addReference('modcodigo', 'modcodigo');
    }
}