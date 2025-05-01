
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class atcoder_ABC120_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (new HashSet<Character>() {{
            for (char c : s.toCharArray()) add(c);
        }}.size() == 1) {
            System.out.println(0);
            System.exit(0);
        }
        Map<Character, Integer> a = new HashMap<>();
        for (char c : s.toCharArray()) {
            a.put(c, a.getOrDefault(c, 0) + 1);
        }
        int ans = Integer.MAX_VALUE;
        for (int value : a.values()) {
            ans = Math.min(ans, value);
        }
        System.out.println(ans * 2);
    }
}

// End of Code.
