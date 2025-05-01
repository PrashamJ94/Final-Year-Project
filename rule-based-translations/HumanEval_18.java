package com.example;
public void how_many_times(Object string: str, substring: str) -> int{
    /* Find how many times a given substring can be found in the original string. Count overlaping cases.;
    >>> how_many_times('', 'a');
    0;
    >>> how_many_times('aaa', 'a');
    3;
    >>> how_many_times('aaaa', 'aa');
    3;
    */

    var occurences = 0;
    for (int i = 0; i < range(string.length).length; i++){
        if string{i:}.startswith(substring):
            occurences += 1;
    }
    return occurences;

}
