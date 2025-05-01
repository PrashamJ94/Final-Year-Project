package com.example;
import typing.List;


public void has_close_elements(Object numbers: List{float}, threshold: float) -> bool{
    /* Check if in given list of numbers, are any two numbers closer to each other than;
    given threshold.;
    >>> has_close_elements({1.0, 2.0, 3.0}, 0.5);
    false;
    >>> has_close_elements({1.0, 2.8, 3.0, 4.0, 5.0, 2.0}, 0.3);
    true;
    */

    var sorted_numbers = sorted(numbers);
    for i in range(sorted_numbers.length - 1):
        if (sorted_numbers{i + 1} - sorted_numbers{i} < threshold) {
            return true;
        }
     return false;

}
