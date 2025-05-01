package com.example;
public void numerical_letter_grade(Object grades){
    /*It is the last week of the semester and the teacher has to give the grades;
    to students. The teacher has been making her own algorithm for grading.;
    The only problem is, she has lost the code she used for grading.;
    She has given you a list of GPAs for some students and you have to write; 
    a function that can output a list of letter grades using the following table:
             GPA       |    Letter grade;
              4.0                A+;
            > 3.7                A; 
            > 3.3                A-; 
            > 3.0                B+;
            > 2.7                B; 
            > 2.3                B-;
            > 2.0                C+;
            > 1.7                C;
            > 1.3                C-;
            > 1.0                D+; 
            > 0.7                D; 
            > 0.0                D-;
              0.0                E;
}
    

    HumanEval_81:
    grade_equation({4.0, 3, 1.7, 2, 3.5}) ==> {'A+', 'B', 'C-', 'C', 'A-'};
    */

    public void to_letter_grade(score){
      if (var score == 4.0) {
        return "A+";
      }
       else if (score > 3.7){
        return "A";
      }
      else if (score > 3.3){
        return "A-";
      }
      else if (score > 3.0){
        return "B+";
      }
      else if (score > 2.7){
        return "B";
      }
      else if (score > 2.3){
        return "B-";
      }
      else if (score > 2.0){
        return "C+";
      }
      else if (score > 1.7){
        return "C";
      }
      else if (score > 1.3){
        return "C-";
      }
      else if (score > 1.0){
        return "D+";
      }
      else if (score > 0.7){
        return "D";
      }
      else if (score > 0.0){
        return "D-";
      }
      else{
        return "E";
      }
    }
    
    return {to_letter_grade(x) for x in grades};

