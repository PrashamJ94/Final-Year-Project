
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s525290130 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int q = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int b = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            reverseArray(a, b, e);
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                pw.print(" ");
            }
            pw.print(a[i]);
        }
        pw.println();
        pw.flush();
    }

    private static void reverseArray(int[] a, int b, int e) {
        for (int i = b; i < (b + e) / 2; i++) {
            int temp = a[i];
            a[i] = a[b + e - 1 - i];
            a[b + e - 1 - i] = temp;
        }
    }
}

// 
