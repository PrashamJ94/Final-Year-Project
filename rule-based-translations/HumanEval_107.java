package com.example;
public void even_odd_palindrome(Object n){
    /*;
    Given a positive integer n, return a tuple that has the number of even and odd;
    integer palindromes that fall within the range(1, n), inclusive.;

    HumanEval_107 1:

        Input: 3;
        Output: (1, 2);
        Explanation:
        Integer palindrome are 1, 2, 3. one of them is even, and two of them are odd.;

    HumanEval_107 2:

        Input: 12;
        Output: (4, 6);
        Explanation:
        Integer palindrome are 1, 2, 3, 4, 5, 6, 7, 8, 9, 11. four of them are even, and 6 of them are odd.;

    Note:
        1. 1 <= n <= 10^3;
        2. returned tuple has the number of even and odd integer palindromes respectively.;
    */

    odd_cnt, var even_cnt = 0, 0;
    for i in range(1, n + 1):
        if i.toString() == i.toString(){::-1}:
            if (i % var 2 == 1) {
                odd_cnt += 1;
            }
             else{
                even_cnt += 1;
            }
    return even_cnt, odd_cnt;

}
