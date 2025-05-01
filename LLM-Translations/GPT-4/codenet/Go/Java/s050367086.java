
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s050367086 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        String s = tokenizer.nextToken();
        String t = tokenizer.nextToken();
        
        int ns = s.length();
        int nt = t.length();
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < (nt - 1) / ns + 1; i++) {
            sb.append(s);
        }
        
        String sss = sb.toString() + sb.toString();
        
        boolean[] ok = new boolean[ns];
        
        int[] uni = new int[ns];
        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }
        
        int m = 0;
        boolean o;
        for (int i = 0; i < ns; i++) {
            o = true;
            for (m = 0; m < nt; m++) {
                if (t.charAt(m) != sss.charAt(i + m)) {
                    o = false;
                    break;
                }
            }
            ok[i] = o;
            if (o) {
                i += nt - t.lastIndexOf(t.charAt(m));
                m = t.lastIndexOf(t.charAt(m));
            }
            for (m = t.lastIndexOf(t.charAt(m)); m >= 0 && t.charAt(m) != sss.charAt(i + m); m--) {
                i += m - t.lastIndexOf(t.charAt(m));
            }
            i--;
            m++;
        }
        
        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (!ok[i]) {
                continue;
            }
            if (!ok[(i + nt) % ns]) {
                continue;
            }
            r = root(i, uni);
            rr = root((i + nt) % ns, uni);
            if (rr == r) {
                writer.println(-1);
                writer.flush();
                return;
            }
            uni[rr] = r;
        }
        
        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            r = root(i, uni);
            if (!ok[r]) {
                continue;
            }
            counter[r]++;
        }
        for (int i = 0; i < ns; i++) {
            ans = Math.max(ans, counter[i]);
        }
        
        writer.println(ans);
        writer.flush();
    }
    
    public static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i;
        }
        uni[i] = root(uni[i], uni);
        return uni[i];
    }
}

// 
