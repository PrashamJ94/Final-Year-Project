import java.util.HashMap;
import java.util.Scanner;

public class s934374308 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int R = sc.nextInt();
        int S = sc.nextInt();
        int P = sc.nextInt();
        String T = sc.next();

        HashMap<String, Integer> dict = new HashMap<>();
        dict.put("r", 0);
        dict.put("s", 0);
        dict.put("p", 0);
        String char;
        boolean[] s = new boolean[N];
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];
        for (int i = 0; i < N; i++) {
            s[i] = true;
            r[i] = true;
            p[i] = true;
        }
        for (int i = 0; i < T.length(); i++) {
            char = T.substring(i, i + 1);
            if (i >= K) {
                if (char.equals(T.substring(i - K, i + 1 - K))) {
                    switch (char) {
                        case "s":
                            if (s[i % K]) {
                                s[i % K] = false;
                                continue;
                            } else {
                                s[i % K] = true;
                            }
                            break;
                        case "r":
                            if (r[i % K]) {
                                r[i % K] = false;
                                continue;
                            } else {
                                r[i % K] = true;
                            }
                            break;
                        case "p":
                            if (p[i % K]) {
                                p[i % K] = false;
                                continue;
                            } else {
                                p[i % K] = true;
                            }
                            break;
                    }
                } else {
                    switch (char) {
                        case "s":
                            s[i % K] = true;
                            break;
                        case "r":
                            r[i % K] = true;
                            break;
                        case "p":
                            p[i % K] = true;
                            break;
                    }
                }
            }
            switch (char) {
                case "s":
                    dict.put("s", dict.get("s") + 1);
                    break;
                case "r":
                    dict.put("r", dict.get("r") + 1);
                    break;
                case "p":
                    dict.put("p", dict.get("p") + 1);
                    break;
            }
        }

        int res = P * dict.get("r") + S * dict.get("p") + R * dict.get("s");
        System.out.println(res);
    }
}
// 
