public class s702834515 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int r = 0;
        for (int ii = 0; ii < n; ii++) {
            if ((ii + 1) % 3 != 0 && (ii + 1) % 5 != 0) {
                r += (ii + 1);
            }
        }
        System.out.println(r);
    }
}
// 
