
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s108967797 {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static double ave(double[] s) {
        double sum = 0;
        for (double v : s) {
            sum += v;
        }
        return sum / s.length;
    }

    public static double diff(double a, double b) {
        return Math.abs(a - b);
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        double ave = ave(a);

        double minDiff = 999999.9;
        int ansIndex = -1;
        for (int i = 0; i < a.length; i++) {
            double diff = diff(a[i], ave);
            if (diff < minDiff) {
                minDiff = diff;
                ansIndex = i;
            }
        }
        System.out.println(ansIndex);
    }
}

// 
