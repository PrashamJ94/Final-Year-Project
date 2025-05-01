package com.example;
public void correct_bracketing(Object brackets: str){
    /* brackets is a string of "<" and ">".;
    return true if every opening bracket has a corresponding closing bracket.;

    >>> correct_bracketing("<");
    false;
    >>> correct_bracketing("<>");
    true;
    >>> correct_bracketing("<<><>>");
    true;
    >>> correct_bracketing("><<>");
    false;
    */

    var cnt = 0;
    for (int x = 0; x < brackets.length; x++){
        if x == "<": cnt += 1;
        if x == ">": cnt -= 1;
        if cnt < 0: return false;
    }
    return cnt == 0;

}
