import java.util.Arrays;
import java.util.Scanner;

public class s273727373 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int[] B = new int[N];
        int count = 1;
        for (int i : A) {
            B[i - 1] = count;
            count++;
        }
        System.out.println(Arrays.toString(B).replace("[", "").replace("]", "").replace(",", ""));
    }
}
// 
