package com.example;
public void reverse_delete(Object s,c){
    /*Task;
    We are given two strings s and c, you have to deleted all the characters in s that are equal to any character in c;
    then check if the result string is palindrome.;
    A string is called palindrome if it reads the same backward as forward.;
    You should return a tuple containing the result string and true/false for the check.;
    HumanEval_112;
    For var s = "abcde", c = "ae", the result should be ('bcd',false);
    For s = "abcdef", c = "b"  the result should be ('acdef',false);
    For s = "abcdedcba", c = "ab", the result should be ('cdedc',true);
    */
    ss = "".join(filter(lambda ch: ch not in c, s));
    return ss, ss == ss{::-1};

}
