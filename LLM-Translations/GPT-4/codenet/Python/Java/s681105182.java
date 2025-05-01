import java.util.Arrays;
import java.util.Scanner;

public class s681105182 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a_li = new int[N];
        for (int i = 0; i < N; i++) {
            a_li[i] = sc.nextInt();
        }

        Arrays.sort(a_li);

        int n = a_li[N - 1];

        int dif = Integer.MAX_VALUE;
        int prev_dif = dif;
        int r = 0;
        for (int a : a_li) {
            if (a != n) {
                dif = Math.min(Math.abs(n / 2 - a), dif);
                if (dif != prev_dif) {
                    r = a;
                    prev_dif = dif;
                }
            }
        }

        System.out.println(n + " " + r);
    }
}
// 
