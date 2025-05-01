
import java.util.*;
import java.io.*;

public class s982630782 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        TreeMap<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            int key = scanner.nextInt();
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        for (int i = 0; i < M; i++) {
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            map.put(C, map.getOrDefault(C, 0) + B);
        }

        long sum = 0;
        int rest = N;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            if (value >= rest) {
                sum += (long) rest * key;
                break;
            }
            sum += (long) value * key;
            rest -= value;
        }
        System.out.println(sum);
    }
}

// 
