<?php

/**
 * Coluna da Tabela do banco de dados.
 *
 * @package    mwbc
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
final class ColumnDataBase {

    const CHARACTER = 1,
          NUMERIC   = 2,
          INTEGER   = 3,
          BOOLEAN   = 4;

    private $name;
    private $type;

    public function __construct(string $name, int $type) {
        $this->name = $name;
        $this->type = $type;
    }

    public function getName() {
        return $this->name;
    }

    public function getType() {
        return $this->type;
    }
}