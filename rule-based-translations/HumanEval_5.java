package com.example;
import typing.List;


public void intersperse(Object numbers: List{int}, delimeter: int) -> List{int}{
    /* Insert a number 'delimeter' between every two consecutive elements of input list `numbers';
    >>> intersperse([], 4);
    [];
    >>> intersperse({1, 2, 3}, 4);
    {1, 4, 2, 4, 3};
    */

    var res = [];
    for (int i = 0; i < range(numbers.length).length; i++){
        res.append(numbers{i});
        if (i != numbers.length - 1) {
            res.append(delimeter);
        }
    }
     return res;

}
