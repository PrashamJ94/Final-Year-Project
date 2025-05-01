
import java.util.Scanner;
import java.util.stream.*;

public class codeforces_519_B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        
        int[] a = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] b = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] c = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        int x = 0;
        int y = 0;
        int z = 0;
        
        for (int i : a) {
            x += i;
        }
        for (int i : b) {
            y += i;
        }
        for (int i : c) {
            z += i;
        }
        
        System.out.println(Math.abs(x - y));
        System.out.println(Math.abs(y - z));
    }
}

// End of Code
