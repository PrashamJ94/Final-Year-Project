package com.example;
public void same_chars(Object s0: str, s1: str){
    /*;
    Check if two words have the same characters.;
    >>> same_chars('eabcdzzzz', 'dddzzzzzzzddeddabc');
    true;
    >>> same_chars('abcd', 'dddddddabc');
    true;
    >>> same_chars('dddddddabc', 'abcd');
    true;
    >>> same_chars('eabcd', 'dddddddabc');
    false;
    >>> same_chars('abcd', 'dddddddabce');
    false;
    >>> same_chars('eabcdzzzz', 'dddzzzzzzzddddabc');
    false;
    */
    return set(s0) == set(s1);

}
