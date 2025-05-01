
import java.util.Scanner;

public class s340712303 {
    static final int N = 2000;
    static int num1;
    static int[] math = new int[N + 1];

    public static void main(String[] args) {
        int a, num2, ans, sum = 0;
        Scanner sc = new Scanner(System.in);

        math[0] = 1;

        num1 = sc.nextInt();
        for (int i = 0; i < num1; i++) {
            a = sc.nextInt();
            sum += a;
            for (int j = sum - a; j >= 0; j--) {
                if (math[j] == 1) math[j + a] = 1;
            }

        }

        num2 = sc.nextInt();
        for (int i = 0; i < num2; i++) {
            ans = sc.nextInt();
            System.out.println(math[ans] == 1 ? "yes" : "no");
        }
    }
}

// 
