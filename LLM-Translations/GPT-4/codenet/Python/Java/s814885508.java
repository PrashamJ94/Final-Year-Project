public class s814885508 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int X = scanner.nextInt();
        int K = scanner.nextInt();
        int D = scanner.nextInt();
        scanner.close();

        int r = X / D;
        if (Math.abs(r) > K) {
            System.out.println(Math.abs(X) - K * D);
        } else {
            int a = X - r * D;
            if ((K - r) % 2 == 0) {
                System.out.println(a);
            } else {
                System.out.println(Math.abs(D - a));
            }
        }
    }
}
// 
