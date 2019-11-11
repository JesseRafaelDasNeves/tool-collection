<?php

/**
 * Modelo dos módulos do sistema.
 *
 * @package    mwst
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
abstract class PersistenceDataBase {

    /** @var Table */
    private $Table;

    /** @var MappingModelDataBase */
    private $aMapping;

    public function __construct() {
        $this->aMapping = Array();
    }

    protected abstract function getInstanceTable() : \TableDataBase;

    protected abstract function createMapping();

    public final function getTabela(): \TableDataBase {
        if (!isset($this->Table)) {
            $this->Table = $this->getInstanceTable();
        }
        return $this->Table;
    }

    protected final function addMappingModel(string $nameModel, string $nameColumn) {
        $oMapping = new MappingModelDataBase($nameModel, $nameColumn);
        $this->aMapping[$nameModel] = $oMapping;
        return $oMapping;
    }

    public final function getMappings() : Array {
        if(!$this->hasMapping()) {
            $this->createMapping();
        }
        return $this->aMapping;
    }

    private final function hasMapping() {
        return count($this->aMapping) > 0;
    }
}
