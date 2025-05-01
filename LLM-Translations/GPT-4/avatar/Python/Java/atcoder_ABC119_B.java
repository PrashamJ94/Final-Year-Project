import java.util.Scanner;

public class atcoder_ABC119_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double[] x = new double[N];
        double total = 0;

        for (int i = 0; i < N; i++) {
            String input = sc.next();
            if (input.contains("JPY")) {
                x[i] = Double.parseDouble(input.replace("JPY", "")) * 1.0;
            } else if (input.contains("BTC")) {
                x[i] = Double.parseDouble(input.replace("BTC", "")) * 380000.0;
            }
            total += x[i];
        }
        System.out.println(total);
    }
}
// End of Code
