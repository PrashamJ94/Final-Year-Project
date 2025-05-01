import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class s013321508 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        ArrayList<Integer> L = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            L.add(sc.nextInt());
        }

        Collections.sort(L);

        int max_L;
        int index;
        for (int i = 0; i < M; i++) {
            max_L = L.get(L.size() - 1);
            if (max_L == 0) {
                break;
            }

            max_L /= 2;
            index = Collections.binarySearch(L, max_L);
            if (index < 0) {
                index = -index - 1;
            }
            L.add(index, max_L);
            L.remove(L.size() - 1);
        }

        long ans = 0;
        for (int l : L) {
            ans += l;
        }

        System.out.println(ans);
    }
}
// 
