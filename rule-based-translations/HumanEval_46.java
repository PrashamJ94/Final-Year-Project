package com.example;
public void fib4(Object n: int){
    /*The Fib4 number sequence is a sequence similar to the Fibbonacci sequnece that's public void ined as follows{
    fib4(0) -> 0;
    fib4(1) -> 0;
    fib4(2) -> 2;
    fib4(3) -> 0;
    fib4(n) -> fib4(n-1) + fib4(n-2) + fib4(n-3) + fib4(n-4).;
    Please write a function to efficiently compute the n-th element of the fib4 number sequence.  Do not use recursion.;
    >>> fib4(5);
    4;
    >>> fib4(6);
    8;
    >>> fib4(7);
    14;
    */
 }
}
    
    if (var n == 0) {
        return 0;
    }
     else if (n == 1){
        return 0;
    }
    else if (n == 2){
        return 2;
    }
    else if (n == 3){
        return 0;
    }
    else{
        a, b, c, var d = 0, 0, 2, 0;
        for i in range(4, n + 1):
            a, b, c, d = b, c, d, a + b + c + d;
        return d;

    }
