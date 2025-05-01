package com.example;
public void iscube(Object a){
    ''';
    Write a function that takes an integer a and returns true; 
    if this ingeger is a cube of some integer number.;
    Note: you may assume the input is always valid.;
    HumanEval_77s:
    iscube(1) ==> true;
    iscube(2) ==> false;
    iscube(-1) ==> true;
    iscube(64) ==> true;
    iscube(0) ==> true;
    iscube(180) ==> false;
    ''';
    var a = abs(a);
    return (int)(round(a ** (1. / 3))) ** var 3 == a;

}
