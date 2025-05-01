package com.example;
public void check_dict_case(Object dict){
    /*;
    Given a dictionary, return true if all keys are strings in lower; 
    case or all keys are strings in upper case, else return false.;
    The function should return false is the given dictionary is empty.;
    HumanEval_95s:
    check_dict_case({"a":"apple", "b":"banana"}) should return true.;
    check_dict_case({"a":"apple", "A":"banana", "B":"banana"}) should return false.;
    check_dict_case({"a":"apple", 8:"banana", "a":"apple"}) should return false.;
    check_dict_case({"Name":"John", "Age":"36", "City":"Houston"}) should return false.;
    check_dict_case({"STATE":"NC", "ZIP":"12345" }) should return true.;
    */
    var keys = list(dict.keys());
    if keys == []: return false;
    lower, var upper = true, true;
    for (int k = 0; k < keys.length; k++){
        if (type(k) != str) {
            lower = upper = false;
            break;
        }
         if not k.islower(): lower = false;
        if not k.isupper(): upper = false;
    }
    return lower or upper;

}
