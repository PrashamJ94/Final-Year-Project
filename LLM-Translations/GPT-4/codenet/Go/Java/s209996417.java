import java.util.Scanner;
import java.lang.Math;

public class s209996417 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n = sc.nextDouble();
        double k = sc.nextDouble();

        double x = 0.0;
        while (true) {
            double under = Math.pow(k, x);
            double upper = Math.pow(k, x + 1);

            if (under <= n && n < upper) {
                System.out.println((int)(x + 1));
                return;
            }
            x++;
        }
    }
}

// 
