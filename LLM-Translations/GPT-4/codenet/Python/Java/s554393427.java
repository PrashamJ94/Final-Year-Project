import java.util.Scanner;

public class s554393427 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[][] mo = new double[N][2];
        for (int i = 0; i < N; i++) {
            double x = scanner.nextDouble();
            String u = scanner.next();
            mo[i][0] = x;
            if (u.equals("JPY")) {
                mo[i][1] = 1;
            } else {
                mo[i][1] = 380000;
            }
        }
        double okz = 0;
        for (int i = 0; i < N; i++) {
            okz += mo[i][0] * mo[i][1];
        }
        System.out.println(okz);
    }
}
// 
