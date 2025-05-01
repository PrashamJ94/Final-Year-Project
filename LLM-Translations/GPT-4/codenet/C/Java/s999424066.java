
import java.util.Scanner;

public class s999424066 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        sc.close();
        c *= 2;

        if (a + b <= c) {
            System.out.println(a * x + b * y);
        } else {
            if (x <= y) {
                if (b <= c) {
                    System.out.println(c * x + (y - x) * b);
                } else {
                    System.out.println(c * y);
                }
            } else {
                if (a <= c) {
                    System.out.println(c * y + (x - y) * a);
                } else {
                    System.out.println(c * x);
                }
            }
        }
    }
}

// 
