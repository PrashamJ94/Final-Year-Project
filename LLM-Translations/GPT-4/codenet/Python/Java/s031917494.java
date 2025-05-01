import java.util.Scanner;

public class s031917494 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();
        int absValue = Math.abs(input - 25);
        StringBuilder result = new StringBuilder("Christmas");
        for (int i = 0; i < absValue; i++) {
            result.append(" Eve");
        }
        System.out.println(result.toString());
    }
}
// 
