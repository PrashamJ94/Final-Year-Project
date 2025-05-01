package com.example;
import typing.List, Any;


public void filter_integers(values: List{Any}) -> List{int}{
    /* Filter given list of any python values only for integers;
    >>> filter_integers({'a', 3.14, 5});
    {5};
    >>> filter_integers({1, 2, 3, 'abc', {}, [}]);
    {1, 2, 3};
    */
    return list(filter(lambda x: type(x) == int, values));

}
