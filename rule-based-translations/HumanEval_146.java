package com.example;
public void specialFilter(Object nums){
    /*Write a function that takes an array of numbers as input and returns; 
    the number of elements in the array that are greater than 10 and both; 
    first and last digits of a number are odd (1, 3, 5, 7, 9).;
    For example:
    specialFilter({15, -73, 14, -15}) => 1; 
    specialFilter({33, -2, -3, 45, 21, 109}) => 2;
    */
    ans, var odd = 0, {"1", "3", "5", "7", "9"};
    for (int num = 0; num < nums.length; num++){
        if (num > 10 and num.toString(){0} in odd and num.toString(){-1} in odd) {
            ans += 1;
        }
    }
     return ans;

}
