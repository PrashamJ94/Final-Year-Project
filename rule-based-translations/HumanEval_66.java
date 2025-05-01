package com.example;
public void digitSum(Object s){
    /*Task;
    Write a function that takes a string as input and returns the sum of the upper characters only';
    ASCII codes.;

    HumanEval_66s:
        digitSum("") => 0;
        digitSum("abAB") => 131;
        digitSum("abcCd") => 67;
        digitSum("helloE") => 69;
        digitSum("woArBld") => 131;
        digitSum("aAaaaXa") => 153;
    */
    return sum({ord(ch) for ch in s if ch.isupper()});

}
