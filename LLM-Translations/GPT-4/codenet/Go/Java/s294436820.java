import java.io.*;
import java.util.*;

public class s294436820 {
    static boolean DEBUG = false;
    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");

        int h = nextInt();
        int w = nextInt();
        int k = nextInt();
        int[][] m = new int[h][w];

        for (int i = 0; i < h; i++) {
            String s = next();
            for (int j = 0; j < w; j++) {
                m[i][j] = (int) s.charAt(j);
            }
        }

        int answer = solve(h, w, k, m);
        out.println(answer);

        out.flush();
    }

    static int Black = 35;

    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        if (DEBUG) {
            out.println("new table");
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == Black) {
                    count++;
                }
            }
            if (DEBUG) {
                out.println(Arrays.toString(m[i]));
            }
        }
        if (DEBUG) {
            out.println("result : " + count);
        }
        return count;
    }

    static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < (1 << h); i++) {
            for (int k = 0; k < (1 << w); k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    tmp[j] = Arrays.copyOf(m[j], w);
                }
                for (int j = 0; j < h; j++) {
                    int hPainted = (1 << j) & i;
                    if (hPainted > 0) {
                        if (DEBUG) {
                            out.println("painted " + j + " " + (1 << j) + " " + i + " " + hPainted);
                        }
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 1;
                        }
                    }
                }
                for (int j = 0; j < w; j++) {
                    int wPainted = (1 << j) & k;
                    if (wPainted > 0) {
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 1;
                        }
                    }
                }
                if (DEBUG) {
                    out.println("i " + Integer.toBinaryString(i));
                    out.println("k " + Integer.toBinaryString(k));
                }
                if (countBlack(h, w, tmp) == a) {
                    result++;
                }
            }
        }
        return result;
    }

    static String next() {
        if (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tok.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }
}
// 
