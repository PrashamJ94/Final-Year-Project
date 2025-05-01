
import java.util.Arrays;
import java.util.Scanner;

public class codeforces_682_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        Arrays.sort(l);
        int c = 0;
        for (int i : l) {
            if (i > c) {
                c += 1;
            }
        }
        System.out.println(c + 1);
    }
}

// End of Code
