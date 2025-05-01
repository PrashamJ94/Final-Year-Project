//java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class s344468705 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < n; i++) {
            solve(br);
        }
    }

    public static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine().trim());
        List<Integer> dp = new ArrayList<>();
        dp.add(Integer.MIN_VALUE);

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine().trim());
            num = -num;
            if (num >= dp.get(dp.size() - 1)) {
                dp.add(num);
            } else {
                int idx = binarySearchRight(dp, num);
                dp.set(idx, num);
            }
        }

        System.out.println(dp.size() - 1);
    }

    public static int binarySearchRight(List<Integer> list, int key) {
        int index = Collections.binarySearch(list, key);
        if (index < 0) {
            index = ~index;
        } else {
            while (index < list.size() && list.get(index) == key) {
                index++;
            }
        }
        return index;
    }
}

// 
