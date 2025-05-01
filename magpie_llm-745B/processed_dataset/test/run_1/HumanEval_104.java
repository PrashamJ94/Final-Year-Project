package com.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class HumanEval_104 {
    private static boolean judge(int x) {
        for (char ch : String.valueOf(x).toCharArray()) {
            if (Character.getNumericValue(ch) % 2 == 0)
                return false;
        }
        return true;
    }

    public static List<Integer> uniqueDigits(List<Integer> x) {
        List<Integer> filteredList = new ArrayList<>();
        for (Integer num : x) {
            if (judge(num))
                filteredList.add(num);
        }
        Collections.sort(filteredList);
        return filteredList;
    }
}