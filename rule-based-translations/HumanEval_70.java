package com.example;
public void strange_sort_list(Object lst){
    ''';
    Given list of integers, return list in strange order.;
    Strange sorting, is when you start with the minimum value,;
    then maximum of the remaining integers, then minimum and so on.;

    HumanEval_70s:
    strange_sort_list({1, 2, 3, 4}) == {1, 4, 2, 3};
    strange_sort_list({5, 5, 5, 5}) == {5, 5, 5, 5};
    strange_sort_list([]) == [];
    ''';
    var sorted_list = sorted(lst);
    ans, i, var j = [], 0, sorted_list.length - 1;
    while (i < j) {
        ans.append(sorted_list{i});
        ans.append(sorted_list{j});
        i += 1;
        j -= 1;
    }
     if var i == j: ans.append(sorted_list{i});
    return ans;

}
