package com.example;
import typing.List;


public void mean_absolute_deviation(Object numbers: List{float}) -> float{
    /* For a given list of input numbers, calculate Mean Absolute Deviation;
    around the mean of this dataset.;
    Mean Absolute Deviation is the average absolute difference between each;
    element and a centerpoint (mean in this case):
    var MAD = average | x - x_mean |;
    >>> mean_absolute_deviation({1.0, 2.0, 3.0, 4.0});
    1.0;
    */
    var mean = sum(numbers) / numbers.length;
    return sum(abs(x - mean) for x in numbers) / numbers.length;

}
