
import java.util.Scanner;

public class s898107093 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] t = new String[n];
        String[] h = new String[n];
        int taro = 0, hanako = 0;

        for (int i = 0; i < n; i++) {
            t[i] = sc.next();
            h[i] = sc.next();
            int compareResult = t[i].compareTo(h[i]);

            if (compareResult < 0) {
                hanako += 3;
            } else if (compareResult > 0) {
                taro += 3;
            } else {
                taro += 1;
                hanako += 1;
            }
        }
        System.out.printf("%d %d%n", taro, hanako);
    }
}

// 
