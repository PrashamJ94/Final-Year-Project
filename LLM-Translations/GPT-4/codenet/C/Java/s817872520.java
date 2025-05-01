
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s817872520 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int w = Integer.parseInt(br.readLine().trim());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] a = new int[w + 2];
        int[] b = new int[w + 2];
        
        int ans, f, i, k, close;
        for (ans = 0, f = 0, i = 1; i <= w; i++) {
            a[i] = k = Integer.parseInt(st.nextToken());
            if (k == 0) f |= 1;
            else if (k < 0) f |= 2;
            else ans += k;
        }
        if (ans == 0 || (f & 1) == 0) { System.out.println("0"); return; }
        if ((f & 2) == 0) { System.out.println(ans); return; }

        for (close = 0, f = 0, i = 1; i <= w; i++) {
            if (a[i] == 0) close = Integer.MAX_VALUE / 2, f = -1;
            else if (a[i] < 0) {
                if (f < 0 || close - (i - f) > -a[i]) close = -a[i], f = i;
            } else {
                if (f < 0) b[i] = Integer.MAX_VALUE / 2;
                else {
                    k = close - (i - f); if (k < 0) k = 0;
                    b[i] = k;
                }
            }
        }

        for (close = 0, f = w, i = w; i >= 1; i--) {
            if (a[i] == 0) close = Integer.MAX_VALUE / 2, f = -1;
            else if (a[i] < 0) {
                if (f < 0 || close - (f - i) > -a[i]) close = -a[i], f = i;
            } else {
                if (f < 0) b[i] = Integer.MAX_VALUE / 2;
                else {
                    k = close - (f - i); if (k < 0) k = 0;
                    if (k > b[i]) b[i] = k;
                }
            }
        }

        for (ans = 0, i = 1; i <= w; i++) {
            if (a[i] > 0) {
                if (b[i] > a[i]) ans += a[i];
                else             ans += b[i];
            }
        }
        System.out.println(ans);
    }
}

// 
