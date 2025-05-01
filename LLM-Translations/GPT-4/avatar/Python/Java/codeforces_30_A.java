public class codeforces_30_A {
    public static void main(String[] args) {
        int A = Integer.parseInt(args[0]);
        int B = Integer.parseInt(args[1]);
        int n = Integer.parseInt(args[2]);
        System.out.println(task4(A, B, n));
    }

    public static String task4(int A, int B, int n) {
        for (int X = -1000; X <= 1000; X++) {
            if (A * Math.pow(X, n) == B) {
                return Integer.toString(X);
            }
        }
        return "No solution";
    }
}
// End of Code
