<?php

/**
 * Classe util para exeções
 *
 * @package
 * @author  Jessé Rafael das Neves
 * @since   28/01/2019
 */
class ExceptionUtils {

    public function treatException(Throwable $Exception) {
        if(!($Exception instanceof ExceptionBaseApp)) {
            $message = "Uma exeção inesperada aconteceu: {$Exception->getMessage()}";
            $oUException = new UnexpectedException($message, 5454);
            throw $oUException;
        } else {
            throw $Exception;
        }
    }

    public function treatError(int $a, string $descricaoErro, string $path, int $linha) {
        throw new UnexpectedError("Um Erro inesperado aconteceu: $descricaoErro em $path linha $linha");
    }

    public function treatExceptionEndExecutionApp() {
        $aError = error_get_last();
    }

}
