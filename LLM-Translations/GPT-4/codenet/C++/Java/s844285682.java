import java.util.Scanner;

public class s844285682 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a;
        
        a = scanner.nextInt();
        
        System.out.printf("%d:%d:%d%n", a / (60 * 60), a % (60 * 60) / 60, a % (60 * 60) % 60);
        
        scanner.close();
    }
}
// 
