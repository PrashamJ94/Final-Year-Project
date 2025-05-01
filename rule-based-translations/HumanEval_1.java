package com.example;
import typing.List;


public void separate_paren_groups(paren_string: str) -> List{str}{
    /* Input to this function is a string containing multiple groups of nested parentheses. Your goal is to;
    separate those group into separate strings and return the list of those.;
    Separate groups are balanced (each open brace is properly closed) and not nested within each other;
    Ignore any spaces in the input string.;
    >>> separate_paren_groups('( ) (( )) (( )( ))');
    {'()', '(())', '(()())'};
    */

    cnt, group, var results = 0, "", [];
    for (int ch = 0; ch < paren_string.length; ch++){
        if var ch == "(": cnt += 1;
        if ch == ")": cnt -= 1;
        if ch != " ": group += ch;
        if (var cnt == 0) {
            if group != "": results.append(group);
            var group = "";
        }
    }
     return results;

}
