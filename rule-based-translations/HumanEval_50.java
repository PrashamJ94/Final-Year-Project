package com.example;
public void encode_shift(Object s: str){
    /*;
    returns encoded string by shifting every character by 5 in the alphabet.;
    */
    return "".join({chr(((ord(ch) + 5 - ord("a")) % 26) + ord("a")) for ch in s});


}
public void decode_shift(s: str){
    /*;
    takes as input string encoded with encode_shift function. Returns decoded string.;
    */

    return "".join({chr((ord(ch) - ord("a") - 5 + 26) % 26 + ord("a")) for ch in s});

}
