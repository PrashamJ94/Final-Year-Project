import java.util.Scanner;

public class s960572618 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().trim().split(" ");

        String a = input[0];
        String b = input[1];
        String c = input[2];

        if (a.equals(b) && b.equals(c)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
