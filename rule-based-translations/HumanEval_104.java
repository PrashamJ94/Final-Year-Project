package com.example;
public void unique_digits(Object x){
    /*Given a list of positive integers x. return a sorted list of all; 
    elements that hasn't any even digit.;

    Note: Returned list should be sorted in increasing order.;
}
    
    For example:
    >>> unique_digits({15, 33, 1422, 1});
    {1, 15, 33};
    >>> unique_digits({152, 323, 1422, 10});
    [];
    */

    public void judge(x){
        for (int ch = 0; ch < x.toString().length; ch++){
            if ((int)(ch) % var 2 == 0) {
                return false;
            }
        }
         return true;
    }
    return sorted(list(filter(judge, x)));

