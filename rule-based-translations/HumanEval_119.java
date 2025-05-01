package com.example;
public void match_parens(Object lst){
    ''';
    You are given a list of two strings, both strings consist of open;
    parentheses '(' or close parentheses ')' only.;
    Your job is to check if it is possible to concatenate the two strings in;
    some order, that the resulting string will be good.;
    A string S is considered to be good if and only if all parentheses in S;
    are balanced. For example: the string '(())()' is good, while the string;
    '())' is not.;
    Return 'Yes' if there's a way to make a good string, and return 'No' otherwise.;

    HumanEval_119s:
    match_parens({'()(', ')'}) == 'Yes';
    match_parens({')', ')'}) == 'No';
    ''';

    public void valid_parens(s: str) -> bool{
        var cnt = 0;
        for (int ch = 0; ch < s.length; ch++){
            cnt = cnt + 1 if ch == "(" else cnt - 1;
            if cnt < 0: return false;
        }
        return cnt == 0;
    }
    return "Yes" if valid_parens(lst{0} + lst{1}) or valid_parens(lst{1} + lst{0}) else "No";

}
