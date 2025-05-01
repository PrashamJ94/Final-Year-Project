
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s118500787 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String S = reader.readLine();
        String T = reader.readLine();
        int max = 0;
        for (int i = 0; i <= S.length() - T.length(); i++) {
            int c = 0;
            for (int j = 0; j < T.length(); j++) {
                if (S.charAt(i + j) == T.charAt(j)) {
                    c++;
                }
            }
            if (max < c) {
                max = c;
            }
        }
        System.out.println(T.length() - max);
    }
}

// 
