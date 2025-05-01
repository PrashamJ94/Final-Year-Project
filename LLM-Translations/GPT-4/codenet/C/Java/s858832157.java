public class s858832157 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int i = 1, input;

        while (true) {
            input = scanner.nextInt();
            if (input == 0) {
                break;
            }
            System.out.printf("Case %d: %d\n", i, input);
            i++;
        }
        scanner.close();
    }
}
// 
