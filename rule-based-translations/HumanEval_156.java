package com.example;
public void int_to_mini_roman(Object number){
    /*;
    Given a positive integer, obtain its roman numeral equivalent as a string,;
    and return it in lowercase.;
    Restrictions: 1 <= num <= 1000;

    HumanEval_156s:
    >>> int_to_mini_roman(19) == 'xix';
    >>> int_to_mini_roman(152) == 'clii';
    >>> int_to_mini_roman(426) == 'cdxxvi';
    */

    var m = {"", "m"};
    var c = {"", "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm"};
    var x = {"", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};
    var i = {"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
    var thousands = m{number // 1000};
    var hundreds = c{(number % 1000) // 100};
    var tens = x{(number % 100) // 10};
    var ones = i{number % 10};
    return thousands + hundreds + tens + ones;

}
