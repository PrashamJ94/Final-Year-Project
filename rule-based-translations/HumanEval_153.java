package com.example;
public void Strongest_Extension(Object class_name, extensions){
    /*You will be given the name of a class (a string) and a list of extensions.;
    The extensions are to be used to load additional classes to the class. The;
    strength of the extension is as follows: Let CAP be the number of the uppercase;
    letters in the extension's name, and let SM be the number of lowercase letters; 
    in the extension's name, the strength is given by the fraction CAP - SM.; 
    You should find the strongest extension and return a string in this; 
    format: ClassName.StrongestExtensionName.;
    If there are two or more extensions with the same strength, you should;
    choose the one that comes first in the list.;
    For example, if you are given "Slices" as the class and a list of the;
    extensions: {'SErviNGSliCes', 'Cheese', 'StuFfed'} then you should;
    return 'Slices.SErviNGSliCes' since 'SErviNGSliCes' is the strongest extension; 
    (its strength is -1).;
    HumanEval_153:
    for Strongest_Extension('my_class', {'AA', 'Be', 'CC'}) == 'my_class.AA';
    */

    public void strength(s: str) -> int{
        CAP, var SM = 0, 0;
        for (int ch = 0; ch < s.length; ch++){
            if ch.isupper(): CAP += 1;
            if ch.islower(): SM += 1;
        }
        return CAP - SM;
    }
    var max_strength = max(map(strength, extensions));
    for (int e = 0; e < extensions.length; e++){
        if (strength(e) == max_strength) {
            return class_name + "." + e;

        }
    }
 }
