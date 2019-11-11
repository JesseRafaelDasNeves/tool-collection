<?php

namespace mwst\persistence;

/**
 * Persistencia das rotinas do sistema.
 *
 * @package    mwst
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
class PersistenceRotina extends \PersistenceDataBase {

    protected function getInstanceTable() : \TableDataBase {
        return new table\TableRotina();
    }

    protected function createMapping() {
        $this->addMappingModel('codigo'       , 'rotcodigo');
        $this->addMappingModel('nome'         , 'rotnome');
        $this->addMappingModel('Modulo.codigo', 'modcodigo');
    }

}