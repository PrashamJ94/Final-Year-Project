
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class codeforces_7_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> alocuente = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            alocuente.add(0);
        }
        int ind = 1;
        sc.nextLine();
        for (int i = 0; i < t; i++) {
            String[] op = sc.nextLine().split(" ");
            if (op[0].equals("alloc")) {
                int pos = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente.get(j) == 0) {
                        pos++;
                        if (pos == Integer.parseInt(op[1])) {
                            for (int k = j - Integer.parseInt(op[1]) + 1; k <= j; k++) {
                                alocuente.set(k, ind);
                            }
                            System.out.println(ind);
                            ind++;
                            break;
                        }
                    } else {
                        pos = 0;
                    }
                }
                if (pos != Integer.parseInt(op[1])) {
                    System.out.println("NULL");
                }
            }
            if (op[0].equals("erase")) {
                int pos = 0;
                if (!alocuente.contains(Integer.parseInt(op[1])) || Integer.parseInt(op[1]) == 0) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                } else {
                    for (int j = 0; j < m; j++) {
                        if (Integer.parseInt(op[1]) > 0 && alocuente.get(j).equals(Integer.parseInt(op[1]))) {
                            alocuente.set(j, 0);
                        }
                    }
                }
            }
            if (op[0].equals("defragment")) {
                int cnt = 0;
                cnt = (int) alocuente.stream().filter(a -> a == 0).count();
                alocuente.removeIf(a -> a == 0);
                for (int j = 0; j < cnt; j++) {
                    alocuente.add(0);
                }
            }
        }
    }
}

// End of Code
