import java.util.Scanner;

public class s025428739 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int sum = A + B;
        int diff = A - B;
        int prod = A * B;
        System.out.println(Math.max(sum, Math.max(diff, prod)));
    }
}
// 
