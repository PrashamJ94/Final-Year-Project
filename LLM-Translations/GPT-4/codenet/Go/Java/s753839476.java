import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s753839476 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        double t = Double.parseDouble(st.nextToken());
        double a = Double.parseDouble(st.nextToken());

        double[] heights = new double[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            heights[i] = Double.parseDouble(st.nextToken());
        }

        double minDiff = Math.abs(t - heights[0] * 0.006 - a);
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - heights[i] * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }

        pw.println(minIdx + 1);
        pw.flush();
    }
}

// 
