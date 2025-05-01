package com.example;
public void add(Object lst){
    /*Given a non-empty list of integers lst. add the even elements that are at odd indices..;


    HumanEval_85s:
        add({4, 2, 6, 7}) ==> 2; 
    */

    var s = 0;
    for i in range(1, lst.length, 2):
        if (lst{i} % var 2 == 0) {
            s += lst{i};
        }
     return s;

}
