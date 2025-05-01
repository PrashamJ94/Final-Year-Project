import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s635098814 {

    private static final int ALPHABET_NUM = 26;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] memo = new int[ALPHABET_NUM];
        Arrays.fill(memo, 0);

        String str;
        while ((str = br.readLine()) != null) {
            char[] S = str.toCharArray();
            if (S.length == 0) {
                break;
            }
            for (char c : S) {
                if ('a' <= c && c <= 'z') {
                    memo[c - 'a']++;
                } else if ('A' <= c && c <= 'Z') {
                    memo[c - 'A']++;
                } else {
                    continue;
                }
            }
        }

        for (int i = 0; i < ALPHABET_NUM; i++) {
            System.out.printf("%c : %d%n", (char) (i + 'a'), memo[i]);
        }
    }
}
// 
