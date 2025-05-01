public class s870102598 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        scanner.close();

        if (c >= a && c <= b) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
