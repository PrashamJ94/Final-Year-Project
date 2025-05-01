import java.util.Scanner;

public class s459892612 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        input.close();

        if (a + b >= c) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
