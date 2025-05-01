import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class atcoder_AGC028_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        String S = scanner.next();
        String T = scanner.next();
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        ArrayList<Double> Number_iMN = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            Number_iMN.add(i * (double) M / N);
        }
        Set<Double> set_iMN = new HashSet<>(Number_iMN);
        Set<Integer> set_j = new HashSet<>();
        for (int j = 0; j < M; j++) {
            set_j.add(j);
        }
        set_iMN.retainAll(set_j);
        ArrayList<Integer> Kaburi_j = new ArrayList<>(set_iMN);
        ArrayList<Integer> Kaburi_i = new ArrayList<>();
        for (int j : Kaburi_j) {
            Kaburi_i.add((int) (j * (double) N / M));
        }
        int counter = 0;
        int Flag = 0;
        int Kaburi_Size = Kaburi_i.size();
        while (counter <= Kaburi_Size - 1) {
            if (list_S[Kaburi_i.get(counter)] == list_T[Kaburi_j.get(counter)]) {
                // pass
            } else {
                Flag = 1;
                break;
            }
            counter += 1;
        }
        if (Flag == 1) {
            System.out.println(-1);
        } else {
            System.out.println((int) (N * (long) M / gcd(N, M)));
        }
    }

    public static int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
// End of Code
