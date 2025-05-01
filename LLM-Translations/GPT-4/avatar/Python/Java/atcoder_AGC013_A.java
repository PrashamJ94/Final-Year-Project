import java.util.*;
import java.io.*;
import java.math.*;
import java.util.stream.*;

public class atcoder_AGC013_A {
    static int mod = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        List<Integer> list = new ArrayList<>();
        list.add(A[0]);

        for (int i = 1; i < N; i++) {
            if (A[i] != A[i - 1]) {
                list.add(A[i]);
            }
        }

        N = list.size();
        int i = 1;
        int ans = 0;

        while (i < N - 1) {
            if ((list.get(i - 1) < list.get(i) && list.get(i) > list.get(i + 1)) || (list.get(i - 1) > list.get(i) && list.get(i) < list.get(i + 1))) {
                ans++;
                i++;
            }
            i++;
        }
        System.out.println(ans + 1);
    }
}
// End of Code
