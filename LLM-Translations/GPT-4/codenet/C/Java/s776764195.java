
public class s776764195 {
    private static final int MAX_N = 2000001;
    private static final int MAX_Ai = 10001;
    private static final int STR_SIZE = 10000010;

    private static int[] A = new int[MAX_N];
    private static int[] B = new int[MAX_N];
    private static char[] str = new char[STR_SIZE];
    private static int p = 0;

    public static void main(String[] args) {
        int n;

        String input = new String(str);
        n = getNum(input);

        for (int i = 1; i <= n; ++i) {
            A[i] = getNum(input);
        }

        countingSort(A, B, MAX_Ai, n);

        StringBuilder output = new StringBuilder();
        for (int i = 1; i < n; ++i) {
            output.append(B[i]).append(' ');
        }
        output.append(B[n]);

        System.out.println(output.toString());
    }

    private static int getNum(String input) {
        int n = 0;
        while (p < input.length() && input.charAt(p) >= '0' && input.charAt(p) <= '9') {
            n = n * 10 + (int) (input.charAt(p) - '0');
            ++p;
        }
        ++p;
        return n;
    }

    private static void countingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[MAX_Ai];
        for (int j = 1; j <= len; ++j) {
            ++C[A[j]];
        }
        for (int i = 1; i <= k; ++i) {
            C[i] += C[i - 1];
        }
        for (int j = len; j > 0; --j) {
            B[C[A[j]]] = A[j];
            --C[A[j]];
        }
    }
}

// 
