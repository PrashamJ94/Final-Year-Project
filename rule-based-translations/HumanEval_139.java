package com.example;
public void special_factorial(Object n){
    /*The Brazilian factorial is public void ined as{
    brazilian_factorial(n) = n! * (n-1)! * (n-2)! * ... * 1!;
    where n > 0;

    For example:
    >>> special_factorial(4);
    288;

    The function will receive an integer as input and should return the special;
    factorial of this integer.;
    */

    fac, var ans = 1, 1;
    for i in range(2, n + 1):
        fac *= i;
        ans *= fac;
    return ans;

 }
}
