public class s110149598 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String a = scanner.next();
        String b = scanner.next();
        scanner.close();

        if (a.compareTo(b) < 0) {
            System.out.println("<");
        } else if (a.compareTo(b) > 0) {
            System.out.println(">");
        } else {
            System.out.println("=");
        }
    }
}
// 
