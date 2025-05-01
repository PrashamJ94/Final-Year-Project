
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;

public class s554024899 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        int xt = -1, yt = -1;
        List<Integer>[] a = new List[]{
                Arrays.asList(1, 3, 5, 7, 8, 10, 12),
                Arrays.asList(4, 6, 9, 11),
                Arrays.asList(2)
        };
        for (int i = 0; i < a.length; i++) {
            for (Integer n : a[i]) {
                if (x == n) {
                    xt = i;
                }
                if (y == n) {
                    yt = i;
                }
            }
        }
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// 
