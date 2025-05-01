public class atcoder_ABC168_B {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int K = scanner.nextInt();
        scanner.nextLine();
        String S = scanner.nextLine();
        scanner.close();
        System.out.println(limitStringLength(K, S));
    }

    public static String limitStringLength(int K, String S) {
        if (S.length() <= K) {
            return S;
        }
        return S.substring(0, K) + "...";
    }
}
// End of Code
