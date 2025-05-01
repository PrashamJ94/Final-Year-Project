import java.util.Scanner;

public class s255858499 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.nextLine());
        int b = Integer.parseInt(sc.nextLine());

        if (a * b % 2 != 0) {
            System.out.println("Odd");
        } else {
            System.out.println("Even");
        }

        sc.close();
    }
}
// 
