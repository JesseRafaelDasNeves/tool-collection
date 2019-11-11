<?php

class SqlFrom implements SqlClause {

    const SPACE_BLOCO_QUERY = "     ";

    /** @var TableDataBase */
    private $Tabela;

    public function __construct(TableDataBase $oTable) {
        $this->Tabela = $oTable;
    }

    public function getQuery() {
        return '     FROM ' . $this->Tabela->getTableNameWithSchema();
    }

    public function getTabela() : TableDataBase {
        return $this->Tabela;
    }
}