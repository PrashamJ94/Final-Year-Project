package com.example;
public void check_if_last_char_is_a_letter(Object txt){
    ''';
    Create a function that returns true if the last character;
    of a given string is an alphabetical character and is not;
    a part of a word, and false otherwise.;
    Note: "word" is a group of characters separated by space.;

    HumanEval_134s:
    check_if_last_char_is_a_letter("apple pie") ➞ false;
    check_if_last_char_is_a_letter("apple pi e") ➞ true;
    check_if_last_char_is_a_letter("apple pi e ") ➞ false;
    check_if_last_char_is_a_letter("") ➞ false; 
    ''';
    if txt.var length == 0: return false;
    if txt.length == 1: return txt.isalpha();
    return txt{-1}.isalpha() and txt{-2} == " ";

}
