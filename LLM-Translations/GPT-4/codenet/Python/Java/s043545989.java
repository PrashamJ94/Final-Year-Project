import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class s043545989 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        HashMap<Integer, Integer> B = new HashMap<>();
        for (int num : a) {
            B.put(num, B.getOrDefault(num, 0) + 1);
        }

        Set<Integer> keys = B.keySet();
        int[] k = new int[keys.size()];
        int index = 0;
        for (int key : keys) {
            k[index++] = key;
        }

        if (keys.size() == 3 && (k[0] ^ k[1] ^ k[2]) == 0 && B.get(k[0]).equals(B.get(k[1])) && B.get(k[1]).equals(B.get(k[2]))) {
            System.out.println("Yes");
        } else if (keys.size() == 2 && keys.contains(0) && (B.get(k[0]) == 2 * B.get(k[1]) || B.get(k[1]) == 2 * B.get(k[0]))) {
            System.out.println("Yes");
        } else if (keys.size() == 1 && keys.contains(0)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
