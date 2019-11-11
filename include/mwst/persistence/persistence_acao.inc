<?php

namespace mwst\persistence;

/**
 * Modelo dos módulos do sistema.
 *
 * @package    mwst
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
class PersistenceAcao extends \PersistenceDataBase {

    protected function getInstanceTable() : \TableDataBase {
        return new table\TableAcao();
    }

    protected function createMapping() {
        $this->addMappingModel('codigo', 'acacodigo');
        $this->addMappingModel('nome'  , 'acanome');
    }

}