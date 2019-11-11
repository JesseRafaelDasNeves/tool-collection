<?php

/**
 * Classe padrão para tabelas do banco de dados.
 *
 * @package stc
 * @author  Jessé Rafael das Neves
 * @since   09/10/2017
 */
abstract class TableDataBase {

    private $name;

    /** @var ColumnDataBase[] */
    private $aColumn;

    /** @var ColumnDataBase[] */
    private $aColumnKey;

    /** @var ForeignKeyDataBase[] */
    private $aForeignKey;

    public function __construct() {
        $this->aColumn     = Array();
        $this->aColumnKey  = Array();
        $this->aForeignKey = Array();
        $this->create();
    }

    public abstract function getTableName() : string;

    protected abstract function createColumns();

    protected abstract function createPrimaryKeyConstraints();

    protected function createForeignKeyConstraints() {}

    public function getSchema() : string {
        return 'public';
    }

    public function getName() {
        return $this->name;
    }

    public final function getTableNameWithSchema() {
        return $this->getSchema() . '.' . $this->name;
    }

    private function create() {
        $this->name = $this->getTableName();
        $this->createColumns();
        $this->createPrimaryKeyConstraints();
        $this->createForeignKeyConstraints();
    }

    protected final function addNewColumn(string $name, int $type) {
        $oColumn = new ColumnDataBase($name, $type);
        $this->addColumn($oColumn);
        return $oColumn;
    }

    protected final function addColumn(ColumnDataBase $oColumn) {
        $this->aColumn[$oColumn->getName()] = $oColumn;
    }

    public function getColumns(): array {
        return $this->aColumn;
    }

    public function getColumnByName(string $name): ColumnDataBase {
        if(!isset($this->aColumn[$name])) {
            throw new Exception("Coluna " . $name . " não existe na tabela " . $this->name);
        }

        return $this->aColumn[$name];
    }

    protected final function addPrimaryKey() {
        $aNameColumn = func_get_args();
        foreach ($aNameColumn as $name) {
            $this->addColumnKey($this->getColumnByName($name));
        }
    }

    protected final function addColumnKey(ColumnDataBase $oColumn) {
        $this->aColumnKey[$oColumn->getName()] = $oColumn;
    }

    public function getPrimaryKey() : Array {
        return $this->aColumnKey;
    }

    protected final function addForeignKey(string $modulo, string $tableClass, string $alias = null) {
        $aliasTratado = (is_null($alias) || (trim($alias) === '')) ? $tableClass : $alias;
        $oForeignKey  = new ForeignKeyDataBase($modulo, $tableClass, $aliasTratado);
        $this->aForeignKey[$aliasTratado] = $oForeignKey;
        return $oForeignKey;
    }

    public function getForeignKeys() {
        return $this->aForeignKey;
    }
}