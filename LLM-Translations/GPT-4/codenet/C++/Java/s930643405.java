import java.util.Scanner;
import java.util.Arrays;

public class s930643405 {
    static boolean[] d = new boolean[10];
    static int n, k;
    static boolean hantei = true;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        for (int i = 0; i < k; ++i) {
            int a = sc.nextInt();
            d[a] = true;
        }
        while (true) {
            int x = n;
            hantei = true;
            while (x != 0) {
                if (d[x % 10]) {
                    hantei = false;
                    break;
                }
                x /= 10;
            }
            if (hantei) {
                System.out.println(n);
                break;
            }
            n++;
        }
    }
}
// 
