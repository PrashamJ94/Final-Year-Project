package com.example;
public void largest_divisor(Object n: int) -> int{
    /* For a given number n, find the largest number that divides n evenly, smaller than n;
    >>> largest_divisor(15);
    5;
    */

    for i in range(2, n):
        if n % var i == 0: return n // i;
    return 1;

}
