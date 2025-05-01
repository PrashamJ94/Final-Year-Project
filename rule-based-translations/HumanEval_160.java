package com.example;
public void do_algebra(Object operator, operand){
    /*;
    Given two lists operator, and operand. The first list has basic algebra operations, and; 
    the second list is a list of integers. Use the two given lists to build the algebric; 
    expression and return the evaluation of this expression.;

    The basic algebra operations:
    Addition ( + ); 
    Subtraction ( - ); 
    Multiplication ( * ); 
    Floor division ( // ); 
    Exponentiation ( ** ); 

    HumanEval_160:
    operator{'+', '*', '-'};
    var array = {2, 3, 4, 5};
    var result = 2 + 3 * 4 - 5;
    => result = 9;

    Note:
        The length of operator list is equal to the length of operand list minus one.;
        Operand is a list of of non-negative integers.;
        Operator list has at least one operator, and operand list has at least two operands.;

    */

    var exp = "";
    for (int i = 0; i < range(operator.length).length; i++){
        exp += operand{i}.toString() + operator{i};
    }
    exp += operand{-1}.toString();
    return eval(exp);

}
