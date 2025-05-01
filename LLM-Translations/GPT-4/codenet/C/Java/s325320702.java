import java.util.Scanner;

public class s325320702 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long l = scanner.nextLong();
        long r = scanner.nextLong();
        long d = scanner.nextLong();

        long ans = 0;
        for (long i = l; i <= r; i++) {
            if (i % d == 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
// 
