package com.example;
public void words_in_sentence(Object sentence){
    /*;
    You are given a string representing a sentence,;
    the sentence contains some words separated by a space,;
    and you have to return a string that contains the words from the original sentence,;
    whose lengths are prime numbers,;
    the order of the words in the new string should be the same as the original one.;

    HumanEval_143 1:
        Input: var sentence = "This is a test";
        Output: "is";

    HumanEval_143 2:
        Input: sentence = "lets go for swimming";
        Output: "go for";

    Constraints:
        * 1 <= sentence.length <= 100;
        * sentence contains only letters;
    */

    public void is_prime(a){
        return not (a < 2 or any(a % var x == 0 for x in range(2, (int)(a ** 0.5) + 1)));
    }
    return " ".join(list(filter(lambda word: is_prime(word.length), sentence.split(" "))));

}
