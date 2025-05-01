import java.util.Scanner;
import java.lang.Math;

public class s465977291 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        double a = d * 2 + 1;
        System.out.println((int) Math.ceil(n / a));
    }
}
// 
