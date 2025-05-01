package com.example;
public void median(Object l: list){
    /*Return median of elements in the list l.;
    >>> median({3, 1, 2, 4, 5});
    3;
    >>> median({-10, 4, 6, 1000, 10, 20});
    15.0;
    */

    var sorted_l = sorted(l);
    if (l.length % var 2 == 1) {
        return sorted_l{l.length // 2};
    }
     else{
        return (sorted_l{l.length // 2 - 1} + sorted_l{l.length // 2}) / 2;

    }
}
