<?php

namespace mwst\classes\model;

/**
 * Modelo dos módulos do sistema.
 *
 * @package    mwbc
 * @subpackage model
 * @author     Jessé Rafael das Neves
 * @since      09/10/2017
 */
class ModelModulo {

    private $codigo;
    private $nome;
    private $ativo;

    public function setCodigo($codigo) {
        $this->codigo = $codigo;
    }

    public function getCodigo() {
        return $this->codigo;
    }

    public function setNome($nome) {
        $this->nome = $nome;
    }

    public function getNome() {
        return $this->nome;
    }

    public function setAtivo($ativo) {
        $this->ativo = $ativo;
    }

    public function getAtivo() {
        return $this->ativo;
    }
}