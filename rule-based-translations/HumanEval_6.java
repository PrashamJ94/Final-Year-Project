package com.example;
import typing.List;


public void parse_nested_parens(paren_string: str) -> List{int}{
    /* Input to this function is a string represented multiple groups for nested parentheses separated by spaces.;
    For each of the group, output the deepest level of nesting of parentheses.;
    E.g. (()()) has maximum two levels of nesting while ((())) has three.;

    >>> parse_nested_parens('(()()) ((())) () ((())()())');
    {2, 3, 1, 3};
    */
}
    
    public void count_depth(s: str) -> int{
        max_depth, var cnt = 0, 0;
        for (int ch = 0; ch < s.length; ch++){
            if var ch == "(": cnt += 1;
            if ch == ")": cnt -= 1;
            var max_depth = max(max_depth, cnt);
        }
        return max_depth;
    }
    
    return {count_depth(s) for s in paren_string.split(" ") if s != ""};

