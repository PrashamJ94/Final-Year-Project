import java.util.Scanner;

public class s557080041 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        if (N == 0) {
            System.out.println("Yes");
        } else {
            String N_str = Integer.toString(N);
            int[] L = new int[N_str.length()];
            for (int i = 0; i < N_str.length(); i++) {
                L[i] = Character.getNumericValue(N_str.charAt(i));
            }
            int X = 0;
            for (int s : L) {
                X += s;
            }
            if (X % 9 == 0) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
// 
