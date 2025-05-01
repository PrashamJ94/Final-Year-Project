import java.util.Scanner;

public class s238775098 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double res = 0;
        for (int i = 0; i < n; i++) {
            double x = sc.nextDouble();
            String u = sc.next();
            if (u.equals("BTC")) {
                res += x * 380000;
            } else {
                res += x;
            }
        }
        System.out.println(res);
    }
}
// 
