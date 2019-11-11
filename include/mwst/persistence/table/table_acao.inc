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
final class TableAcao extends \TableDataBase {

    public function getTableName(): string {
        return 'tbacao';
    }

    protected function createColumns() {
        $this->addNewColumn('acacodigo', \ColumnDataBase::INTEGER);
        $this->addNewColumn('acanome'  , \ColumnDataBase::CHARACTER);
    }

    protected function createPrimaryKeyConstraints() {
        $this->addPrimaryKey('acacodigo');
    }

}