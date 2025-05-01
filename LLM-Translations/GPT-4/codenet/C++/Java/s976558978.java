import java.io.*;
import java.util.*;

public class s976558978 {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        if (a < b) {
            for (int i = 0; i < b; i++) {
                out.write(a + "");
            }
            out.newLine();
        } else {
            for (int i = 0; i < a; i++) {
                out.write(b + "");
            }
            out.newLine();
        }
        out.flush();
        in.close();
        out.close();
    }
}
// 
