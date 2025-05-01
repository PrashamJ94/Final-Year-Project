public class s666154520 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 1; i < 100000; i++) {
            if (i * i > n) {
                System.out.println((i - 1) * (i - 1));
                break;
            }
        }
    }
}
// 
