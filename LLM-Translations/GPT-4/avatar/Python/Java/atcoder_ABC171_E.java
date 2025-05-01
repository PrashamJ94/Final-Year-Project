import java.util.Scanner;
import java.util.Arrays;

public class atcoder_ABC171_E {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = in.nextInt();
        }

        int total = 0;
        for (int ai : a) {
            total ^= ai;
        }

        int[] result = Arrays.stream(a).map(ai -> ai ^ total).toArray();
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]);
            if (i < result.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
// End of Code.
