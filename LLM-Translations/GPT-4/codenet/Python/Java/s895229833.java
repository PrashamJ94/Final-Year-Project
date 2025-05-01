//java
import java.util.Scanner;

public class s895229833 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] H = new int[N];
        for (int i = 0; i < N; i++) {
            H[i] = sc.nextInt();
        }

        int countBest = 0, countTmp = 0;

        for (int i = 0; i < N - 1; i++) {
            if (H[i] >= H[i + 1]) {
                countTmp++;
            } else {
                if (countTmp > countBest) {
                    countBest = countTmp;
                }
                countTmp = 0;
            }
        }

        if (countTmp > countBest) {
            countBest = countTmp;
        }

        System.out.println(countBest);
    }
}

// 
