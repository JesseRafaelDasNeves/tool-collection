<?php

class SqlWhere implements SqlClause {

    private $aCondicoes;

    public function __construct() {
        $this->aCondicoes = Array();
    }

    public function getQuery() {
        return ' WHERE ' . $this->getCondicoesAsString();
    }

    public function addCondicao(string $column, string $operador = Sql::OPERADOR_IGUAL, $valor_1 = null, $valor_2 = null) {
        $this->aCondicoes[] = $column . ' ' . $operador . ' ' . $valor_1;
    }

    private function getCondicoesAsString() {
        return implode(' AND ', $this->aCondicoes);
    }
}