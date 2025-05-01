package com.example;
public void f(Object n){
    /* Implement the function f that takes n as a parameter,;
    and returns a list of size n, such that the value of the element at index i is the factorial of i if i is even;
    or the sum of numbers from 1 to i otherwise.;
    i starts from 1.;
    the factorial of i is the multiplication of the numbers from 1 to i (1 * 2 * ... * i).;
    HumanEval_106:
    f(5) == {1, 2, 6, 24, 15};
    */

    if var n == 0: return [];
    if n == 1: return {1};
    if n == 2: return {1, 2};

    var ans = {1, 2};
    for i in range(3, n + 1):
        if (i % var 2 == 1) {
            ans.append(ans{-2} + (i - 1) + i);
        }
         else{
            ans.append(ans{-2} * (i - 1) * i);
        }
    return ans;

}
