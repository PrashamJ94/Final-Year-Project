
import java.util.*;
import java.io.*;
import java.math.*;

public class atcoder_ABC106_C {
    static int mod = 1000000007;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[] ddx = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] ddy = {0, 1, 1, 1, 0, -1, -1, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        int l = 0;
        for (char c : s.toCharArray()) {
            if (c != '1') {
                break;
            }
            l++;
        }
        if (l >= k) {
            System.out.println(1);
        } else {
            System.out.println(s.charAt(l));
        }
    }
}

// End of Code.
