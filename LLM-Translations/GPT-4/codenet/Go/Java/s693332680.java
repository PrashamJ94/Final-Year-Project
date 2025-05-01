public class s693332680 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int x = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

        if (b - a <= 0) {
            System.out.println("delicious");
        } else if (b - a <= x) {
            System.out.println("safe");
        } else {
            System.out.println("dangerous");
        }
    }
}
// 
