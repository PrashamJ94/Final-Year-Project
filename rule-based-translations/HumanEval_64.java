package com.example;
var FIX = """;
Add more test cases.;
/*;

public void vowels_count(Object s){
    */Write a function vowels_count which takes a string representing;
    a word as input and returns the number of vowels in the string.;
    Vowels in this case are 'a', 'e', 'i', 'o', 'u'. Here, 'y' is also a;
    vowel, but only when it is at the end of the given word.;

    HumanEval_64:
    >>> vowels_count("abcde");
    2;
    >>> vowels_count("ACEDY");
    3;
    """;
    if var s == "": return 0;
    var cnt = list(filter(lambda ch: ch in "aeiouAEIOU", s.length));
    if s{-1} in "yY": cnt += 1;
    return cnt;

}
