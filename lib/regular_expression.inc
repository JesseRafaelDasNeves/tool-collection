<?php

/**
 * Interface de expressões regulares.
 *
 * @package Structure
 * @author  Jessé Rafael das Neves
 * @since   11/05/2017
 */
class RegularExpression {

    const UPPER_CASE_NOT_FIRST = '/\B([A-Z])/',//Coincide apenas maiúsculas menos o primeiro caracter.
          UPPER_CASE           = '/([A-Z])/';  //Coincide apenas maiúsculas.

    public static function uppercaseToUnderscore(string $work, bool $first = false) {
        $pattern = $first ? self::UPPER_CASE : self::UPPER_CASE_NOT_FIRST;
        $function = function($aCharacter) {
            return '_' . $aCharacter[0];
        };
        return strtolower(preg_replace_callback($pattern, $function, $work));
    }
}