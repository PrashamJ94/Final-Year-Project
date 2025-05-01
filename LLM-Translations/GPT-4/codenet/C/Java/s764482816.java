public class s764482816 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int[] io = new int[5];
        for (int i = 0; i < 5; i++) {
            io[i] = sc.nextInt();
        }
        sc.close();

        for (int i = 0; i < 5; i++) {
            int max = io[i];
            int max_j = i;
            for (int j = i + 1; j < 5; j++) {
                if (max < io[j]) {
                    max = io[j];
                    max_j = j;
                }
            }
            int buf = io[i];
            io[i] = io[max_j];
            io[max_j] = buf;
            if (i < 4) {
                System.out.print(io[i] + " ");
            } else {
                System.out.print(io[i] + "\n");
            }
        }
    }
}
// 
