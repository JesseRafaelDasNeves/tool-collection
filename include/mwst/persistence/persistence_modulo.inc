<?php

namespace mwst\persistence;

/**
 * Persistencia dos módulos do sistema.
 *
 * @package    mwst
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      23/10/2017
 */
class PersistenceModulo extends \PersistenceDataBase {

    protected function getInstanceTable(): \TableDataBase {
        return new table\TableModulo();
    }

    protected function createMapping() {
        $this->addMappingModel('codigo', 'modcodigo');
        $this->addMappingModel('nome'  , 'modnome');
        $this->addMappingModel('ativo' , 'modativo');
    }

}