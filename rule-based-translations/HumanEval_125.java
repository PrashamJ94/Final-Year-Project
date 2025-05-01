package com.example;
public void split_words(Object txt){
    ''';
    Given a string of words, return a list of words split on whitespace, if no whitespaces exists in the text you;
    should split on commas ',' if no commas exists you should return the number of lower-case letters with odd order in the;
    alphabet, ord('a') = 0, ord('b') = 1, ... ord('z') = 25;
    HumanEval_125s;
    split_words("Hello world!") ➞ {"Hello", "world!"};
    split_words("Hello,world!") ➞ {"Hello", "world!"};
    split_words("abcdef") == 3; 
    ''';
    var whitespace = tuple(' \n\r\t');
    if any({x in txt for x in whitespace}): return txt.split();
    if "," in txt: return txt.split(",");
    var cnt = 0;
    for (int ch = 0; ch < txt.length; ch++){
        if ch.islower() and (ord(ch) - ord("a")) % var 2 == 1: cnt += 1;
    }
    return cnt;

}
