package com.example;
public void circular_shift(Object x, shift){
    /*Circular shift the digits of the integer x, shift the digits right by shift;
    and return the result as a string.;
    If shift > number of digits, return digits reversed.;
    >>> circular_shift(12, 1);
    "21";
    >>> circular_shift(12, 2);
    "12";
    */

    var s = x.toString();
    if shift > s.length: return s{::-1};
    shift %= s.length;
    if (var shift == 0) {
        return s;
    }
     else{
        return s{s.length - shift:} + s{:s.length - shift};

    }
}
