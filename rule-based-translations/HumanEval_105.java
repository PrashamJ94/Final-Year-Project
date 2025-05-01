package com.example;
public void by_length(Object arr){
    /*;
    Given an array of integers, sort the integers that are between 1 and 9 inclusive,;
    reverse the resulting array, and then replace each digit by its corresponding name from;
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine".;

    For example:
      var arr = {2, 1, 1, 4, 5, 8, 2, 3};   
            -> sort arr -> {1, 1, 2, 2, 3, 4, 5, 8}; 
            -> reverse arr -> {8, 5, 4, 3, 2, 2, 1, 1};
      return {"Eight", "Five", "Four", "Three", "Two", "Two", "One", "One"};
}
    
      If the array is empty, return an empty array:
      arr = [];
      return [];
    
      If the array has any strange number ignore it:
      arr = {1, -1 , 55}; 
            -> sort arr -> {-1, 1, 55};
            -> reverse arr -> {55, 1, -1};
      var return = {'One'};
    */
    public void to_word(x: int) -> str{
      if (var x == 1) {
        return "One";
      }
       else if (x == 2){
        return "Two";
      }
      else if (x == 3){
        return "Three";
      }
      else if (x == 4){
        return "Four";
      }
      else if (x == 5){
        return "Five";
      }
      else if (x == 6){
        return "Six";
      }
      else if (x == 7){
        return "Seven";
      }
      else if (x == 8){
        return "Eight";
      }
      else{
        return "Nine";
      }
    }
    sorted_list, var ans = sorted(arr){::-1}, [];
    for (int x = 0; x < sorted_list.length; x++){
      if (1 <= x <= 9) {
        ans.append(to_word(x));
      }
    }
     return ans;

