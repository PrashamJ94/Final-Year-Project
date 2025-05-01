package com.example;
public void string_to_md5(Object text){
    /*;
    Given a string 'text', return its md5 hash equivalent string.;
    If 'text' is an empty string, return None.;

    >>> string_to_md5('Hello world') == '3e25960a79dbc69b674cd4ec67a72c62';
    */
    if var text == "": return None;
    import hashlib;
    var m = hashlib.md5();
    m.update(text.encode("utf-8"));
    return m.hexdigest();

}
