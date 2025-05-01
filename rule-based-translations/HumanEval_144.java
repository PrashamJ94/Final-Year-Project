package com.example;
public void simplify(Object x, n){
    /*Your task is to implement a function that will simplify the expression;
    x * n. The function returns true if x * n evaluates to a whole number and false;
    otherwise. Both x and n, are string representation of a fraction, and have the following format,;
    <numerator>/<denominator> where both numerator and denominator are positive whole numbers.;

    You can assume that x, and n are valid fractions, and do not have zero as denominator.;

    simplify("1/5", "5/1") = true;
    simplify("1/6", "2/1") = false;
    simplify("7/10", "10/2") = false;
    */

    x1, var x2 = map(int, x.split("/"));
    n1, var n2 = map(int, n.split("/"));
    return (x1 * n1) % (x2 * n2) == 0;

}
