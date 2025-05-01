public class s067092519 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][][] m = new int[4][3][10];
        for (int i = 0; i < N; i++) {
            int b = sc.nextInt();
            int f = sc.nextInt();
            int r = sc.nextInt();
            int v = sc.nextInt();
            m[b - 1][f - 1][r - 1] += v;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 10; k++) {
                    System.out.print(" " + m[i][j][k]);
                }
                System.out.println();
            }
            if (i < 3) {
                System.out.println("####################");
            }
        }
    }
}
// 
