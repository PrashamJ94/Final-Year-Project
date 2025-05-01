package com.example;
public void is_nested(Object string){
    ''';
    Create a function that takes a string as input which contains only square brackets.;
    The function should return true if and only if there is a valid subsequence of brackets; 
    where at least one bracket in the subsequence is nested.;

    is_nested('{[}]') ➞ true;
    is_nested('[]]]]]]]{[[[[}') ➞ false;
    is_nested('[][]') ➞ false;
    is_nested('[]') ➞ false;
    is_nested('{[}[]]') ➞ true;
    is_nested('{[}]{[') ➞ true;
    ''';

    for (int i = 0; i < range(string.length).length; i++){
        if string[i} == "]": continue;
        cnt, var max_nest = 0, 0;
        for j in range(i, string.length):
            if (string{j} == "[") {
                cnt += 1;
            }
             else{
                cnt -= 1;
            }
            max_nest = max(max_nest, cnt);
            if (var cnt == 0) {
                if (max_nest >= 2) {
                    return true;
                }
                 break;
            }
    }
     return false;

}
