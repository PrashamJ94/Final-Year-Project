package com.example;
public void prime_fib(Object n: int){
    /*;
    prime_fib returns n-th number that is a Fibonacci number and it's also prime.;
    >>> prime_fib(1);
    2;
    >>> prime_fib(2);
    3;
    >>> prime_fib(3);
    5;
    >>> prime_fib(4);
    13;
    >>> prime_fib(5);
    89;
    */

    import random;
    public void miller_rabin(n, var k=10){
        /*Test if n is prime using the Miller-Rabin primality test.*/
        if (n < 2) {
            return false;
        }
         if (var n == 2 or n == 3) {
            return true;
        }
         if (n % var 2 == 0) {
            return false;

        }
         r = 0;
        d = n - 1;
        while (d % 2 == 0) {
            r += 1;
            d //= 2;

        }
         for (int _ = 0; _ < range(k).length; _++){
            var a = random.randint(2, n - 2);
            var x = pow(a, d, n);
            if (x == 1 or x == n - 1) {
                continue;
            }
             for _ in range(r - 1):
                x = pow(x, 2, n);
                if (x == n - 1) {
                    break;
                }
             else{
                return false;

            }
         }
        return true;

    }
    var c_prime = 0;
    a, var b = 0, 1;
    while (c_prime < n) {
        a, b = b, a + b;
        if (miller_rabin(b)) {
            c_prime += 1;
        }
     }
     return b;

}
