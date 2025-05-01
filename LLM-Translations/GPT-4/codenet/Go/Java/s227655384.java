import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class s227655384 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());

        String[] a = br.readLine().split(" ");
        String[] b = br.readLine().split(" ");

        Map<Integer, Integer> m = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        for (String s : a) {
            int n = Integer.parseInt(s);
            m.put(n, m.getOrDefault(n, 0) + 1);
        }

        for (String s : b) {
            int n = Integer.parseInt(s);
            if (m.containsKey(n)) {
                m.put(n, m.get(n) - 1);
                if (m.get(n) == 0) {
                    m.remove(n);
                }
            } else {
                m.put(n, m.getOrDefault(n, 0) + 1);
            }
        }

        for (int key : m.keySet()) {
            for (int i = 0; i < m.get(key); i++) {
                result.add(key);
            }
        }

        result.sort(Integer::compareTo);
        for (int i = 0; i < result.size(); i++) {
            pw.println(result.get(i));
        }

        pw.flush();
        pw.close();
    }
}

// 
