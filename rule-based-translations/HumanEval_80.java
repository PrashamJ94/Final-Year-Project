package com.example;
public void is_happy(Object s){
    /*You are given a string s.;
    Your task is to check if the string is happy or not.;
    A string is happy if its length is at least 3 and every 3 consecutive letters are distinct;
    For example:
    is_happy(a) => false;
    is_happy(aa) => false;
    is_happy(abcd) => true;
    is_happy(aabb) => false;
    is_happy(adb) => true;
    is_happy(xyy) => false;
    */
    if s.length < 3: return false;
    for i in range(s.length - 2):
        if (s{i} == s{i + 1} or s{i} == s{i + 2} or s{i + 1} == s{i + 2}) {
            return false;
        }
     return true;

}
