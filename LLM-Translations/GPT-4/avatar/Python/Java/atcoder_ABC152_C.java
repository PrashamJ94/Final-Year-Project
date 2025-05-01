
import java.util.Scanner;
import java.util.Arrays;

public class atcoder_ABC152_C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        int[] n = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int a = 1;
        int pos = 0;
        for (int i = 1; i < N; i++) {
            if (n[pos] > n[i]) {
                a += 1;
                pos = i;
            }
        }
        System.out.println(a);
    }
}

// End of Code
