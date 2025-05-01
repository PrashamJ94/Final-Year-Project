import java.util.Arrays;
import java.util.Scanner;

public class s635143344 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] in = new int[3];
        in[0] = sc.nextInt();
        in[1] = sc.nextInt();
        in[2] = sc.nextInt();
        Arrays.sort(in);

        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}
// 
