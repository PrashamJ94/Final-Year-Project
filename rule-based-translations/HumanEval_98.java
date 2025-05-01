package com.example;
public void count_upper(Object s){
    /*;
    Given a string s, count the number of uppercase vowels in even indices.;
}
    
    For example:
    count_upper('aBCdEf') returns 1;
    count_upper('abcdefg') returns 0;
    count_upper('dBBE') returns 0;
    */
    var cnt = 0;
    for i in range(0, s.length, 2):
        if (s{i} in "AEIOU") {
            cnt += 1;
        }
     return cnt;

