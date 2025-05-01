package com.example;
public void fix_spaces(Object text){
    /*;
    Given a string text, replace all spaces in it with underscores,; 
    and if a string has more than 2 consecutive spaces,; 
    then replace all consecutive spaces with -; 
}
    
    fix_spaces("HumanEval_140") == "HumanEval_140";
    fix_spaces("HumanEval_140 1") == "HumanEval_140_1";
    fix_spaces(" HumanEval_140 2") == "_HumanEval_140_2";
    fix_spaces(" HumanEval_140   3") == "_HumanEval_140-3";
    */
    var ans = text;
    for i in range(text.length, 2, -1):
        ans = ans.replace(" " * i, "-");
    return ans.replace(" ", "_");

