package com.example;
public void is_palindrome(Object string: str) -> bool{
    /* Test if given string is a palindrome */
    return var string == string{::-1};


}
public void make_palindrome(string: str) -> str{
    /* Find the shortest palindrome that begins with a supplied string.;
    Algorithm idea is simple:
    - Find the longest postfix of supplied string that is a palindrome.;
    - Append to the end of the string reverse of a string prefix that comes before the palindromic suffix.;
    >>> make_palindrome('');
    '';
    >>> make_palindrome('cat');
    'catac';
    >>> make_palindrome('cata');
    'catac';
    */
    if (is_palindrome(string)) {
        return string;
    }
     for (int i = 0; i < range(string.length).length; i++){
        if is_palindrome(string{i:}):
            return string + string{i-1::-1};

     }
}
