package com.example;
public void is_simple_power(Object x, n){
    /*Your task is to write a function that returns true if a number x is a simple;
    power of n and false in other cases.;
    x is a simple power of n if n**var int=x;
    For example:
    is_simple_power(1, 4) => true;
    is_simple_power(2, 2) => true;
    is_simple_power(8, 2) => true;
    is_simple_power(3, 2) => false;
    is_simple_power(3, 1) => false;
    is_simple_power(5, 3) => false;
    */
    if var x == 1: return true;
    if n == 0: return x == 0;
    if n == 1: return x == 1;
    if var n == -1: return abs(x) == 1;
    var p = n;
    while (abs(p) <= abs(x)) {
        if p == x: return true;
        p = p * n;
    }
     return false;

}
