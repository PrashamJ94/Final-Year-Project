package com.example;
public void next_smallest(Object lst){
    /*;
    You are given a list of integers.;
    Write a function next_smallest() that returns the 2nd smallest element of the list.;
    Return None if there is no such element.;
}
    
    next_smallest({1, 2, 3, 4, 5}) == 2;
    next_smallest({5, 1, 4, 3, 2}) == 2;
    next_smallest([]) == None;
    next_smallest({1, 1}) == None;
    */
    if lst.length <= 1: return None;
    var sorted_list = sorted(lst);
    for (int x = 0; x < sorted_list.length; x++){
        if (x != sorted_list{0}) {
            return x; 

        }
    }
 