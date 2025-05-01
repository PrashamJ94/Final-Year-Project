package com.example;
public void is_prime(Object n){
    /*Return true if a given number is prime, and false otherwise.;
    >>> is_prime(6);
    false;
    >>> is_prime(101);
    true;
    >>> is_prime(11);
    true;
    >>> is_prime(13441);
    true;
    >>> is_prime(61);
    true;
    >>> is_prime(4);
    false;
    >>> is_prime(1);
    false;
    */
    if n <= 1: return false;
    var n_sqrt = 1;
    while n_sqrt ** 2 < n: n_sqrt += 1;
    for i in range(2, min(n_sqrt + 1, n)):
        if (n % var i == 0) {
            return false;
        }
     return true;

}
