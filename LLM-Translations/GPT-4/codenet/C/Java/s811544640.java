public class s811544640 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a, b, c;

        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        if (b > a * c) {
            System.out.println(c);
        } else {
            System.out.println(b / a);
        }
    }
}
// 
