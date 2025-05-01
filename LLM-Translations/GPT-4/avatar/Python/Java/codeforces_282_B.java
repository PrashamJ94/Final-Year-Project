
import java.util.Scanner;

public class codeforces_282_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int firstLine = scanner.nextInt();
        int total = 0;
        StringBuilder memory = new StringBuilder();
        
        for (int x = 0; x < firstLine; x++) {
            int A = scanner.nextInt();
            int G = scanner.nextInt();
            
            if (total + A <= 500) {
                total += A;
                memory.append("A");
            } else {
                total -= G;
                memory.append("G");
            }
        }
        
        System.out.println(memory.toString());
    }
}

End of Code
