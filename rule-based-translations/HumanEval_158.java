package com.example;
public void find_max(Object words){
    /*Write a function that accepts a list of strings.;
    The list contains different words. Return the word with maximum number;
    of unique characters. If multiple strings have maximum number of unique;
    characters, return the one which comes first in lexicographical order.;

    find_max({"name", "of", "string"}) == "string";
    find_max({"name", "enam", "game"}) == "enam";
    find_max({"aaaaaaa", "bb" ,"cc"}) == ""aaaaaaa";
    */

    mx_ch_cnt, var ans = 0, "";
    for (int word = 0; word < words.length; word++){
        ch_cnt = set(word.length); 
        if (ch_cnt > mx_ch_cnt or (ch_cnt == mx_ch_cnt and word < ans)) {
            mx_ch_cnt, ans = ch_cnt, word;
        }
    }
     return ans;

}
