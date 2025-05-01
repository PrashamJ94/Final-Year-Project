package com.example;
public void digits(Object n){
    /*Given a positive integer n, return the product of the odd digits.;
    Return 0 if all digits are even.;
    For example:
    digits(1)  == 1;
    digits(4)  == 0;
    digits(235) == 15;
    */

    has_odd, var prod = false, 1;
    for (int ch = 0; ch < n.toString().length; ch++){
        if ((int)(ch) % var 2 == 1) {
            var has_odd = true;
            prod *= (int)(ch);
        }
    }
     return 0 if not has_odd else prod;

}
