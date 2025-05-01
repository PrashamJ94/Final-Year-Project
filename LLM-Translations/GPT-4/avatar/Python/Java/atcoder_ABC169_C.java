import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class atcoder_ABC169_C {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String sa = st.nextToken();
        String sb = st.nextToken();
        int a = Integer.parseInt(sa);
        int b = (int) Math.round(Double.parseDouble(sb) * 100);
        System.out.println(a * b / 100);
    }
}

// End of Code.
