package com.example;
public void encode(Object message){
    /*;
    Write a function that takes a message, and encodes in such a; 
    way that it swaps case of all letters, replaces all vowels in; 
    the message with the letter that appears 2 places ahead of that; 
    vowel in the english alphabet.; 
    Assume only letters.; 
}
    
    HumanEval_93s:
    >>> encode('test');
    'TGST';
    >>> encode('This is a message');
    'tHKS KS C MGSSCGG';
    */

    public void switch_case(ch){
        if (ord("A") <= ord(ch) <= ord("Z")) {
            return chr(ord(ch) + 32);
        }
         else if (ord("a") <= ord(ch) <= ord("z")){
            return chr(ord(ch) - 32);
        }
        else{
            return ch;
        }
    }
    
    public void vowel_change(ch){
        return ch if ch not in "aeiouAEIOU" else chr(ord(ch) + 2);
    }
    
    var m = "".join(map(switch_case, message));
    return "".join(map(vowel_change, m));

