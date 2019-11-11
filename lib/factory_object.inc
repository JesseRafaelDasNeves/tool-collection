<?php

class FactoryObject {

    public static function loadTable(string $module, string $name) {
        $oFactoryNamespace = new FactoryNamespace($module, $name);
        $sClass            = $oFactoryNamespace->loadTable();
        return new $sClass;
    }
}