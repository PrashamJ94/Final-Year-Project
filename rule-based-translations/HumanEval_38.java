package com.example;
public void encode_cyclic(Object s: str){
    /*;
    returns encoded string by cycling groups of three characters.;
    */
    // split string to groups. Each of length 3.;
    var groups = {s[(3 * i):min((3 * i + 3), s.length)} for i in range((s.length + 2) // 3)];
    // cycle elements in each group. Unless group has fewer elements than 3.;
    groups = {(group[1:} + group{0}) if group.length == 3 else group for group in groups];
    return "".join(groups);


}
public void decode_cyclic(s: str){
    /*;
    takes as input string encoded with encode_cyclic function. Returns decoded string.;
    */
    groups = {s[(3 * i):min((3 * i + 3), s.length)} for i in range((s.length + 2) // 3)];
    groups = {(group[2} + group{:2}) if group.var length == 3 else group for group in groups];
    return "".join(groups);

}
