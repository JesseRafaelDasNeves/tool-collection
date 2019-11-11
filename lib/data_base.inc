<?php

/**
 * Informação do Banco de dados.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   18/05/2017
 */
final class DataBase {

    const DMS_PG = 'postgres';//Data Manager System pg

    private $banco;
    private $driver;
    private $host;
    private $port;
    private $Name;
    private $user;
    private $password;

    public function setBanco($banco) {
        $this->banco = $banco;
    }

    public function getBanco() {
        return $this->banco;
    }

    public function setDriver($driver) {
        $this->driver = $driver;
    }

    public function getDriver() {
        return $this->driver;
    }

    public function setHost($host) {
        $this->host = $host;
    }

    public function getHost() {
        return $this->host;
    }

    public function setPort($port) {
        $this->port = $port;
    }

    public function getPort() {
        return $this->port;
    }

    public function setName($Name) {
        $this->Name = $Name;
    }

    public function getName() {
        return $this->Name;
    }

    public function setUser($user) {
        $this->user = $user;
    }

    public function getUser() {
        return $this->user;
    }

    public function setPassword($password) {
        $this->password = $password;
    }

    public function getPassword() {
        return $this->password;
    }

    public function getMap() : string {
        return $this->getDriver() . ':host=' . $this->getHost() . ';port=' . $this->getPort() . ';dbname=' . $this->getName();
    }
}