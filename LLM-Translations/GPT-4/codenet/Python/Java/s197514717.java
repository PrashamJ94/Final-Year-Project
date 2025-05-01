import java.util.*;

public class s197514717 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int C = Integer.parseInt(input[2]);
        
        int result = Math.max(Math.max(10 * A + B + C, 10 * B + C + A), 10 * C + A + B);
        System.out.println(result);
    }
}
// 
