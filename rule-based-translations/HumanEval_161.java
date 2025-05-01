package com.example;
public void solve(Object s){
    /*You are given a string s.;
    if s{i} is a letter, reverse its case from lower to upper or vise versa,; 
    otherwise keep it as it is.;
    If the string contains no letters, reverse the string.;
    The function should return the resulted string.;
    HumanEval_161s;
    solve("1234") = "4321";
    solve("ab") = "AB";
    solve(";//a@C") = "#A@c"
    */
    ans, var has_letter = "", false;
    for (int ch = 0; ch < s.length; ch++){
        if (ch.isalpha()) {
            has_letter = true;
            ans += ch.swapcase();
        }
         else{
            ans += ch;
        }
    }
    return ans if has_letter else s{::-1};

}
