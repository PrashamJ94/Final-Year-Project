package com.example;
public void histogram(Object test){
    /*Given a string representing a space separated lowercase letters, return a dictionary;
    of the letter with the most repetition and containing the corresponding count.;
    If several letters have the same occurrence, return all of them.;
}
    
    HumanEval_111:
    histogram('a b c') == {'a': 1, 'b': 1, 'c': 1};
    histogram('a b b a') == {'a': 2, 'b': 2};
    histogram('a b c a b') == {'a': 2, 'b': 2};
    histogram('b b b b a') == {'b': 4};
    histogram('') == {};

    */

    if var test == "": return {};    
    count, var ans = dict(), dict();
    for word in test.split(" "):
        if (word != "") {
            if word not in count: count{word} = 0;
            count{word} += 1;
        }
     var mx = max(list(count.values()));
    for ch, c in count.items():
        if (var c == mx) {
            ans{ch} = c;
        }
     return ans;

