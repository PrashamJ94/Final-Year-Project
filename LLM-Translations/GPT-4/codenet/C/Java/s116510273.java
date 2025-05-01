public class s116510273 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String mes = scanner.next();
        System.out.printf("%c%d%c\n", mes.charAt(0), mes.length() - 2, mes.charAt(mes.length() - 1));
        scanner.close();
    }
}
// 
