
import java.util.Scanner;

public class s792612560 {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        long m = n;
        n--;

        for (; n > 1; n--) {
            m *= n;
        }
        System.out.println(m);
    }
}

// 
