<?php

/**
 * Configurações do cliente.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   18/05/2017
 */
final class FactoryClientSettings {

    /**
     * Retorna a caonfiguração conforme o cliente.
     *
     * @todo Alterar para fazer o load conforme parametrização do cliente.
     *
     * @return ClientSettings
     */
    public static function load() {
        return new ClientSettings('Padrao');
    }
}