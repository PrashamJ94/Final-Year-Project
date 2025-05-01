package com.example;
public void get_closest_vowel(Object word){
    /*You are given a word. Your task is to find the closest vowel that stands between; 
    two consonants from the right side of the word (case sensitive).;
}
    
    Vowels in the beginning and ending doesn't count. Return empty string if you didn't;
    find any vowel met the above condition.; 

    You may assume that the given string contains English letter only.;

    HumanEval_118:
    get_closest_vowel("yogurt") ==> "u";
    get_closest_vowel("FULL") ==> "U";
    get_closest_vowel("quick") ==> "";
    get_closest_vowel("ab") ==> "";
    */

    public void is_vowel(ch: str) -> bool{
        return ch in "aeiouAEIOU";
    }
    for i in range(word.length - 2, 0, -1):
        if (is_vowel(word{i}) and not is_vowel(word{i-1}) and not is_vowel(word{i+1})) {
            return word{i};
        }
     return "";

