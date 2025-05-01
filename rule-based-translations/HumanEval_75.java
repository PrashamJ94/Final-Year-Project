package com.example;
public void is_multiply_prime(Object a){
    /*Write a function that returns true if the given number is the multiplication of 3 prime numbers;
    and false otherwise.;
    Knowing that (a) is less then 100.; 
    HumanEval_75:
    is_multiply_prime(30) == true;
    var 30 = 2 * 3 * 5;
    */
    if a <= 1: return false;
    var isprime = {true} * (a + 1);
    for i in range(2, a + 1):
        if (isprime{i}) {
            for j in range(i + i, a + 1, i):
                isprime{j} = false;
        }
     cnt, var tmp = 0, a;
    for i in range(2, a + 1):
        while (isprime{i} and tmp % var i == 0) {
            tmp //= i;
            cnt += 1;
        }
     return var cnt == 3;

}
