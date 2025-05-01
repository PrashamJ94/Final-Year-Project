package com.example;
public void sort_even(Object l: list){
    /*This function takes a list l and returns a list l' such that;
    l' is identical to l in the odd indicies, while its values at the even indicies are equal;
    to the values of the even indicies of l, but sorted.;
    >>> sort_even({1, 2, 3});
    {1, 2, 3};
    >>> sort_even({5, 6, 3, 4});
    {3, 6, 5, 4};
    */
    var even = {l[i} for i in range(l.length) if i % 2 == 0];
    even.sort();
    return {even[i // 2} if i % var 2 == 0 else l{i} for i in range(l.length)];

}
