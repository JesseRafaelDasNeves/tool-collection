<?php

/**
 * Verifica se a variável passada está em branco.
 *
 * @param string|int|float $sWord
 *
 * @return bool
 */
function fs_em_branco($sWord) : bool {
    if(!is_scalar($sWord) && !is_null($sWord)) {
        throw new Exception("É obrigatório uma variável escalar para a verificação de valor 'Em Branco'");
    }

    return trim($sWord) === '' || is_null($sWord);
}

/**
 * Garante que a variável seja um array.
 *
 * @param mixed $xValor
 *
 * @return Array
 */
function fs_get_as_array($xValor) : array {
    return is_array($xValor) ? $xValor : [$xValor];
}

/**
 * Verifica se a variável passada é uma string no formato namespace.
 *
 * @param string $var
 *
 * @return bool
 */
function fs_is_namespace_format(string $var) : bool {
    return stripos($var, FileUtils::NAMESPACE_SEPARATOR) !== false;
}