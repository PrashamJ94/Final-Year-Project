
import java.util.Scanner;

public class s445709355 {

    public static int[] f1 = new int[100], f2 = new int[100];

    public static void calc(int n) {
        int k = n % 10;
        while (n >= 10) n /= 10;
        ++f1[10*k + n];
        ++f2[n*10 + k];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int ans = 0;

        while (N != 0) {
            calc(N--);
        }

        for (int i = 0; i < 100; ++i) ans += f1[i] * f2[i];
        System.out.println(ans);
    }
}

// 
