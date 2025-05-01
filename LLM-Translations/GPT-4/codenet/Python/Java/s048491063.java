public class s048491063 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int Q = scanner.nextInt();
        int[][] train = new int[N][N];
        for (int m = 0; m < M; m++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            train[l - 1][r - 1]++;
        }

        int[][] accum = new int[N + 1][N + 1];
        for (int i = 0; i < N; i++) {
            int v = 0;
            for (int j = 0; j < N; j++) {
                v += train[i][j];
                accum[i + 1][j + 1] = accum[i][j + 1] + v;
            }
        }

        for (int q = 0; q < Q; q++) {
            int p = scanner.nextInt();
            int qIndex = scanner.nextInt();
            int v = accum[qIndex][qIndex] - accum[p - 1][qIndex] - accum[qIndex][p - 1] + accum[p - 1][p - 1];
            System.out.println(v);
        }
    }
}
// 
