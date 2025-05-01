
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s814977152 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        int[] tomatu = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            tomatu[i] = A[i];
        }

        Arrays.sort(tomatu);

        int yukinnko = 1;
        for (int i = 1; i < N; i++) {
            if (tomatu[i] != tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[i];
            }
        }

        Map<Integer, Boolean> mikakosi = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int kugyu = Arrays.binarySearch(tomatu, 0, yukinnko, A[i]);
            mikakosi.put(kugyu, !mikakosi.getOrDefault(kugyu, false));
        }

        int emirinn = 0;
        for (int i = 0; i < yukinnko; i++) {
            if (mikakosi.getOrDefault(i, false)) {
                emirinn++;
            }
        }

        System.out.println(emirinn);
    }
}

// 
