import java.util.*;

public class s893778513 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        int[] l = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int b = Arrays.stream(l).max().getAsInt();
        int s = Arrays.stream(l).sum();

        if (b < s - b) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
