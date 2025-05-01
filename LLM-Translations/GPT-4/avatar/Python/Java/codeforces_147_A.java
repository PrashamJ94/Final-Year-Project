
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class codeforces_147_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        List<String> res = new ArrayList<>();
        List<Character> punctuation = Arrays.asList(',', '.', '!', '?');

        for (int i = 0; i < s.length(); i++) {
            if (i >= 1) {
                if (s.charAt(i) == ' ') {
                    if (!res.get(res.size() - 1).equals(" ")) {
                        res.add(Character.toString(s.charAt(i)));
                    }
                } else {
                    if (punctuation.contains(s.charAt(i))) {
                        if (res.get(res.size() - 1).equals(" ")) {
                            res.remove(res.size() - 1);
                        }
                        res.add(Character.toString(s.charAt(i)));
                        res.add(" ");
                    } else {
                        res.add(Character.toString(s.charAt(i)));
                    }
                }
            } else {
                if (s.charAt(i) == ' ') {
                    continue;
                }
                if (punctuation.contains(s.charAt(i))) {
                    continue;
                } else {
                    res.add(Character.toString(s.charAt(i)));
                }
            }
        }
        System.out.println(String.join("", res));
    }
}

// End of Code
