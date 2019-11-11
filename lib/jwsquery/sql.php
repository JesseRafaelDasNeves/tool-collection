<?php

class Sql  {

    const SPACE_BLOCO_QUERY = "    ";

    const OPERADOR_IGUAL = '=';

    /** @var SqlSelect */
    private $Select;

    /** @var SqlFrom */
    private $From;

    /** @var SqlWhere */
    private $Where;

    public function __construct(TableDataBase $oTable) {
        $teste = dirname(__FILE__);
        $this->Select = new SqlSelect();
        $this->From   = new SqlFrom($oTable);
        $this->Where  = new SqlWhere();
    }

    public function addColumnBySelect(string $column, string $alias = null) {
        $this->Select->addColumn($column, $alias);
    }

    public function addColumnBySql($oSql, $alias) {
        $this->Select->addColumnBySql($oSql, $alias);
    }

    public function addCondicao(string $column, string $operador = Sql::OPERADOR_IGUAL, $valor_1 = null, $valor_2 = null) {
        $this->Where->addCondicao($column, $operador, $valor_1, $valor_2);
    }

    public function getQuery() {
        $sQuery  = $this->Select->getQuery() . StringUtils::ENTER;
        $sQuery .= $this->From->getQuery()   . StringUtils::ENTER;
        $sQuery .= $this->Where->getQuery()  . StringUtils::ENTER;

        return $sQuery;
    }

    public function __toString() {
        return $this->getQuery();
    }
}