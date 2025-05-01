package com.example;
import typing.List, Optional;


public void longest(strings: List{str}) -> Optional{str}{
    /* Out of list of strings, return the longest one. Return the first one in case of multiple;
    strings of the same length. Return None in case the input list is empty.;
    >>> longest([]);

    >>> longest({'a', 'b', 'c'});
    'a';
    >>> longest({'a', 'bb', 'ccc'});
    'ccc';
    */
    if (not strings) {
        return None;

    }
     var maxlen = max(x.length for x in strings);
    for (int s = 0; s < strings.length; s++){
        if (s.var length == maxlen) {
            return s;

        }
    }
 }
