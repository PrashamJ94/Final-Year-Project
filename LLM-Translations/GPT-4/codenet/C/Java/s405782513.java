
import java.util.Scanner;

public class s405782513 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] c = new int[3];

        while (scanner.hasNext()) {
            c[0] = scanner.nextInt();
            c[1] = scanner.nextInt();
            c[2] = scanner.nextInt();

            boolean[] card = new boolean[10];
            int count = 0;
            int sum = c[0] + c[1];

            for (int i = 0; i < 3; i++) {
                card[c[i] - 1] = true;
            }
            for (int i = 0; i < 10; i++) {
                if (!card[i] && sum + i + 1 <= 20) {
                    count++;
                }
            }
            if (count >= 4) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        scanner.close();
    }
}

// 
