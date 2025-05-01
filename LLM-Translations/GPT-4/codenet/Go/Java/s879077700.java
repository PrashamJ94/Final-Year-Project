public class s879077700 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String a = scanner.next();
        String ans = "Good";
        for (int i = 0; i < 3; i++) {
            if (a.charAt(i) == a.charAt(i + 1)) {
                ans = "Bad";
            }
        }
        System.out.println(ans);
    }
}
// 
