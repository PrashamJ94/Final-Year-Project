public class codeforces_110_B {
    public static void main(String[] args) {
        String LUCKY = "abcd";
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        String s = "";
        for (int i = 0; i < n; i++) {
            s += LUCKY.charAt(i % 4);
        }
        System.out.println(s);
    }
}
// End of Code
