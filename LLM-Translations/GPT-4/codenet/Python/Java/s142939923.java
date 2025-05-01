import java.util.Scanner;

public class s142939923 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // A + B
        int x = a + b;
        // A - B
        int y = a - b;
        // A * B
        int z = a * b;
        
        int max = Math.max(x, Math.max(y, z));
        System.out.println(max);
    }
}
// 
