//java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class s975943078 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        String[] A_str = br.readLine().split(" ");
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = (Integer.parseInt(A_str[i]) % K) - 1;
        }
        int[] sum_A = new int[N + 1];

        int count = 0;
        Map<Integer, List<Integer>> modK = new HashMap<>();
        modK.put(0, new ArrayList<>());
        modK.get(0).add(0);
        for (int i = 0; i < N; i++) {
            sum_A[i + 1] = (sum_A[i] + A[i]) % K;
            if (!modK.containsKey(sum_A[i + 1])) {
                modK.put(sum_A[i + 1], new ArrayList<>());
            }
            modK.get(sum_A[i + 1]).add(i + 1);
        }

        for (Integer key : modK.keySet()) {
            List<Integer> lenK = modK.get(key);
            for (int i = 0; i < lenK.size(); i++) {
                int a = lenK.get(i);
                count += bisect_left(lenK, a + K, i) - i - 1;
            }
        }

        System.out.println(count);
    }

    public static int bisect_left(List<Integer> list, int value, int start) {
        int low = start;
        int high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}

// 
