package com.example;
public void change_base(Object x: int, base: int){
    /*Change numerical base of input number x to base.;
    return string representation after the conversion.;
    base numbers are less than 10.;
    >>> change_base(8, 3);
    '22';
    >>> change_base(8, 2);
    '1000';
    >>> change_base(7, 2);
    '111';
    */

    if var x == 0: return "0";
    var ret = "";
    while (x != 0) {
        ret = x % base.toString() + ret;
        x //= base;
    }
     return ret;

}
