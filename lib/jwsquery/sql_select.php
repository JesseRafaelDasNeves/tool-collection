<?php

class SqlSelect implements SqlClause {

    const SPACE_BLOCO_QUERY = "          ";

    private $Column = [];

    public function addColumn(string $column, string $alias = null) {
        if(is_null($alias)) {
            $alias = $column;
        }
        $this->Column[$alias] = $column;
    }

    public function getColumns() {
        return $this->Column;
    }

    public function addColumnBySql(Sql $oSql, string $alias) {
        $this->Column[$alias] = $oSql;
    }

    public function getQuery() {
        $query  = '   SELECT ';
        $query .= implode(',' . StringUtils::ENTER . self::SPACE_BLOCO_QUERY, $this->getQueryColumnsAsArray());
        return $query;
    }

    private function getQueryByColumn(string $column, string $alias) {
        if($column === $alias) {
            return $column;
        }
        return $column . ' AS "' . $alias . '"';
    }

    private function getQueryByColumnSql(Sql $oSql, string $alias) {
        return '(' . $oSql->getQuery() . ') AS ' . $alias;
    }

    private function getQueryColumnsAsArray() {
        $aQueryColumn = Array();
        foreach ($this->Column as $alias => $xColumn) {
            if($xColumn instanceof Sql) {
                $aQueryColumn[] = $this->getQueryByColumnSql($xColumn, $alias);
            } else {
                $aQueryColumn[] = $this->getQueryByColumn($xColumn, $alias);
            }
        }
        return $aQueryColumn;
    }
}