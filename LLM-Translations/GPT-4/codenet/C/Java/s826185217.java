
import java.util.Scanner;

public class s826185217 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int a, b, c, d;

        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        if (a + b > c + d) System.out.println("Left");
        else if (a + b < c + d) System.out.println("Right");
        else System.out.println("Balanced");
    }
}

// 
