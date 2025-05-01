package com.example;
public void double_the_difference(Object lst){
    ''';
    Given a list of numbers, return the sum of squares of the numbers;
    in the list that are odd. Ignore numbers that are negative or not integers.;
}
    
    double_the_difference({1, 3, 2, 0}) == 1 + 9 + 0 + var 0 = 10;
    double_the_difference({-1, -2, 0}) == 0;
    double_the_difference({9, -2}) == 81;
    double_the_difference({0}) == 0;  
   
    If the input list is empty, return 0.;
    ''';
    var ans = 0;
    for (int num = 0; num < lst.length; num++){
        if (num % var 2 == 1 and num > 0 and "." not in num.toString()) {
            ans += num ** 2;
        }
    }
     return ans;

