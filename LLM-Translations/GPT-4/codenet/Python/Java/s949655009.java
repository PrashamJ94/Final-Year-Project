//java
import java.util.ArrayList;
import java.util.Scanner;

public class s949655009 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String strn = scanner.next();
        int n = Integer.parseInt(strn);
        String[] shichigolist = {"3", "5", "7"};
        ArrayList<ArrayList<String>> shichigo = new ArrayList<>();

        for (int i = 0; i < strn.length(); i++) {
            shichigo.add(new ArrayList<>());
            if (i == 0) {
                for (String j : shichigolist) {
                    shichigo.get(i).add(j);
                }
            } else {
                for (String j : shichigo.get(i - 1)) {
                    for (String k : shichigolist) {
                        shichigo.get(i).add(j + k);
                    }
                }
            }
        }

        int target = strn.length() - 1;
        for (int i = 0; i < strn.length(); i++) {
            for (int j = 0; j < shichigo.get(i).size(); j++) {
                String item = shichigo.get(i).get(j);
                if (i == target) {
                    if (Integer.parseInt(item) > n) {
                        shichigo.get(target).remove(item);
                        j--;
                    } else if (!item.contains("3") || !item.contains("5") || !item.contains("7")) {
                        shichigo.get(target).remove(item);
                        j--;
                    }
                } else {
                    if (!item.contains("3") || !item.contains("5") || !item.contains("7")) {
                        shichigo.get(i).remove(item);
                        j--;
                    }
                }
            }
        }

        int sum = 0;
        for (ArrayList<String> list : shichigo) {
            sum += list.size();
        }
        System.out.println(sum);
    }
}
// 


