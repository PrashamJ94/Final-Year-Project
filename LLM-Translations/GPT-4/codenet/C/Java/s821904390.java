public class s821904390 {
    public static void main(String[] args) {
        int input, h, m, s;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        input = scanner.nextInt();

        h = input / 3600;
        input %= 3600;

        m = input / 60;
        input %= 60;

        s = input;

        System.out.printf("%d:%d:%d\n", h, m, s);
    }
}
// 
