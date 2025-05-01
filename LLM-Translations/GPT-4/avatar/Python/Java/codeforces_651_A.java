import java.util.Scanner;

public class codeforces_651_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        System.out.println(Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0));

        int num_inp = scanner.nextInt();
        int[] arr_inp = new int[num_inp];
        for (int i = 0; i < num_inp; i++) {
            arr_inp[i] = scanner.nextInt();
        }

        int sp_inp1 = scanner.nextInt();
        int sp_inp2 = scanner.nextInt();

        String str_inp = scanner.next();
    }
}
// End of Code
