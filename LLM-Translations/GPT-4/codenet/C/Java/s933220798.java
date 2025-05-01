
import java.util.Scanner;

public class s933220798 {
    public static void main(String[] args) {
        double a;
        double ave = 0;
        int i;
        Scanner scanner = new Scanner(System.in);
        
        for (i = 0; i < 5; i++) {
            a = scanner.nextDouble();
            if (a <= 40) {
                ave += 40;
            }
            else {
                ave += a;
            }
        }
        
        ave /= 5.0;
        
        System.out.printf("%.0f%n", ave);
    }
}

// 
