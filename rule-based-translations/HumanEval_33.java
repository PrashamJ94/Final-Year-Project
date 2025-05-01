package com.example;
public void sort_third(Object l: list){
    /*This function takes a list l and returns a list l' such that;
    l' is identical to l in the indicies that are not divisible by three, while its values at the indicies that are divisible by three are equal;
    to the values of the corresponding indicies of l, but sorted.;
    >>> sort_third({1, 2, 3});
    {1, 2, 3};
    >>> sort_third({5, 6, 3, 4, 8, 9, 2});
    {2, 6, 3, 4, 8, 9, 5};
    */
    var third = {l[i} for i in range(l.length) if i % 3 == 0];
    third.sort();
    return {third[i // 3} if i % var 3 == 0 else l{i} for i in range(l.length)];

}
