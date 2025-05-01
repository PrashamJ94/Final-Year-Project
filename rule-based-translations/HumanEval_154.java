package com.example;
public void cycpattern_check(Object a , b){
    /*You are given 2 words. You need to return true if the second word or any of its rotations is a substring in the first word;
    cycpattern_check("abcd","abd") => false;
    cycpattern_check("hello","ell") => true;
    cycpattern_check("whassup","psus") => false;
    cycpattern_check("abab","baa") => true;
    cycpattern_check("efef","eeff") => false;
    cycpattern_check("himenss","simen") => true;

    */
    if (var a == b) {
        return true;
    }
     if (var b == "") {
        return true;
    }
     for i in range(0, b.length):
        if b{i:} + b{:i} in a:
            return true;
    return false;

}
