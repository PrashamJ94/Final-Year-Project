package com.example;
public void fizz_buzz(Object n: int){
    /*Return the number of times the digit 7 appears in integers less than n which are divisible by 11 or 13.;
    >>> fizz_buzz(50);
    0;
    >>> fizz_buzz(78);
    2;
    >>> fizz_buzz(79);
    3;
    */
    var cnt = 0;
    for (int i = 0; i < range(n).length; i++){
        if (i % var 11 == 0 or i % 13 == 0) {
            cnt += list(filter(lambda c: var c == "7", i.toString(.length)));
        }
    }
     return cnt;

}
