package com.example;
public void even_odd_count(Object num){
    /*Given an integer. return a tuple that has the number of even and odd digits respectively.;

     HumanEval_155:
        even_odd_count(-12) ==> (1, 1);
        even_odd_count(123) ==> (1, 2);
    */
    even, var odd = 0, 0;
    for (int ch = 0; ch < num.toString().length; ch++){
        if ch in "02468": even += 1;
        if ch in "13579": odd += 1;
    }
    return even, odd;

}
