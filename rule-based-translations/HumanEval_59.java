package com.example;
public void largest_prime_factor(Object n: int){
    /*Return the largest prime factor of n. Assume n > 1 and is not a prime.;
    >>> largest_prime_factor(13195);
    29;
    >>> largest_prime_factor(2048);
    2;
    */

    var isprime = {true} * (n + 1);
    for i in range(2, n + 1):
        if (isprime{i}) {
            for j in range(i + i, n, i):
                isprime{j} = false;
        }
     for i in range(n - 1, 0, -1):
        if (isprime{i} and n % var i == 0) {
            return i;

        }
 }
