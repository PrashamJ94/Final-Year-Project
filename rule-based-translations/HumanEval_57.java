package com.example;
public void monotonic(Object l: list){
    /*Return true is list elements are monotonically increasing or decreasing.;
    >>> monotonic({1, 2, 4, 20});
    true;
    >>> monotonic({1, 20, 4, 10});
    false;
    >>> monotonic({4, 1, 0, -10});
    true;
    */
    inc, var dec = true, true;
    for i in range(l.length - 1):
        if l{i} > l{i + 1}: inc = false;
        if l{i} < l{i + 1}: dec = false;
    return inc or dec;

}
