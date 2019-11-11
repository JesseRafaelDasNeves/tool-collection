<?php

/**
 * Classe de conexao com o banco de dados.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   03/05/2017
 */
class ConnectionDataBase {

    /** @var DataBase */
    private $DataBase;

    /** @var PDO */
    private $PDO;

    public function __construct(DataBase $oDataBase) {
        $this->DataBase = $oDataBase;
        $this->connect();
    }

    private function connect() {
        try {
            $this->PDO = new PDO($this->DataBase->getMap(), $this->DataBase->getUser(), $this->DataBase->getPassword());
            $this->setApplicationName();
        } catch (PDOException $ex) {
            throw new Exception($ex->getMessage());
        }
    }

    public function getDataBase() {
        return $this->DataBase;
    }

    public function begin() {
        $this->PDO->beginTransaction();
    }

    public function beginTransactionExists() {
        if($this->inTransaction()) {
            $this->begin();
        }
    }

    public function commit() {
        $this->PDO->commit();
    }

    public function commitTransactionExists() {
        if($this->inTransaction()) {
            $this->commit();
        }
    }

    public function rollback() {
        $this->PDO->rollBack();
    }

    public function rollbackTransactionExists() {
        if($this->inTransaction()) {
            $this->rollback();
        }
    }

    public function inTransaction() {
        return $this->PDO->inTransaction();
    }

    private function setApplicationName() {
        $oProjeto = new Project();
        (new ReaderSettingsObjectType($oProjeto))->read();
        $this->PDO->query("SET APPLICATION_NAME = '{$oProjeto->getName()} - Jesse Teste - Mudar Isso'");
    }

    public function __destruct() {
        $this->rollbackTransactionExists();
    }

}