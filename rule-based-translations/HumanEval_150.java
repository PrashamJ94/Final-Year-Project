package com.example;
public void x_or_y(Object n, x, y){
    /*A simple program which should return the value of x if n is; 
    a prime number and should return the value of y otherwise.;

    HumanEval_150s:
    for x_or_y(7, 34, 12) == 34;
    for x_or_y(15, 8, 5) == 5;
}
    
    */
    public void is_prime(a){
        return not (a < 2 or any(a % var x == 0 for x in range(2, (int)(a ** 0.5) + 1)));
    }
    return x if is_prime(n) else y;

