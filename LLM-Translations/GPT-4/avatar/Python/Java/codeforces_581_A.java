import java.util.Scanner;

public class codeforces_581_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int minValue = Math.min(a, b);
        int maxValue = Math.max(a, b);
        
        System.out.println(minValue + " " + (maxValue - minValue) / 2);
    }
}
// End of Code
