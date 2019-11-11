<?php

require_once 'lib\configuration_app.inc';

$oScript = new ConfigurationApp();
$oScript->load();

$oMain = MainInfo::getInstance();
//$oMain->dfjgnjdfnl;

$oPersistencia = new mwst\persistence\PersistenceAcao();
$oTabela       = $oPersistencia->getTabela();

$oPersistenciaRot = new mwst\persistence\PersistenceRotina();
$oTabela       = $oPersistenciaRot->getTabela();

$oSql = new Sql($oTabela);
$oSql->addColumnBySelect('rotcodigo', 'codigo_rotina');
$oSql->addColumnBySelect('rotnome');
$oSql->addCondicao('rotcodigo', Sql::OPERADOR_IGUAL, 1);
$query = $oSql->getQuery();

/*$oObject = new stdClass();
$oObject->prop_1 = 'Nissan GTR';
$oObject->prop_2 = 1;
$oObject->prop_3 = 5.5;

echo json_encode($oObject);*/

//$oTeste = new ModelTeste();

echo $query;
echo '<br>';
echo "Script Ok!!!<br>";