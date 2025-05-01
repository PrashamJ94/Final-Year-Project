import java.util.Scanner;

public class s257064825 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        int sum = 0;
        
        for (char x : str.toCharArray()) {
            sum += (x - 48);
        }
        
        if (sum % 9 == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }
}
// 
