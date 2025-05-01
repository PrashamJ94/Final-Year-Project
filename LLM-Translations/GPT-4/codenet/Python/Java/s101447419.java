import java.util.*;

public class s101447419 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = sc.nextInt();
        }
        List<Integer> ve = new ArrayList<>();
        List<Integer> vo = new ArrayList<>();
        for (int i = 0; i < n / 2; i++) {
            ve.add(v[2 * i]);
            vo.add(v[2 * i + 1]);
        }
        Map<Integer, Integer> ce = new HashMap<>();
        Map<Integer, Integer> co = new HashMap<>();
        for (int num : ve) {
            ce.put(num, ce.getOrDefault(num, 0) + 1);
        }
        for (int num : vo) {
            co.put(num, co.getOrDefault(num, 0) + 1);
        }
        int ans = n;
        int maxCeKey = Collections.max(ce.entrySet(), Map.Entry.comparingByValue()).getKey();
        int maxCeValue = Collections.max(ce.entrySet(), Map.Entry.comparingByValue()).getValue();
        int maxCoKey = Collections.max(co.entrySet(), Map.Entry.comparingByValue()).getKey();
        int maxCoValue = Collections.max(co.entrySet(), Map.Entry.comparingByValue()).getValue();
        if (maxCeKey != maxCoKey) {
            ans = n - maxCeValue - maxCoValue;
        } else if (ce.size() == 1 && co.size() == 1) {
            ans = n - maxCeValue;
        } else if (ce.size() == 1) {
            co.remove(maxCoKey);
            int secondMaxCoValue = Collections.max(co.entrySet(), Map.Entry.comparingByValue()).getValue();
            ans = n - maxCeValue - secondMaxCoValue;
        } else if (co.size() == 1) {
            ce.remove(maxCeKey);
            int secondMaxCeValue = Collections.max(ce.entrySet(), Map.Entry.comparingByValue()).getValue();
            ans = n - secondMaxCeValue - maxCoValue;
        } else {
            ce.remove(maxCeKey);
            co.remove(maxCoKey);
            int secondMaxCeValue = Collections.max(ce.entrySet(), Map.Entry.comparingByValue()).getValue();
            int secondMaxCoValue = Collections.max(co.entrySet(), Map.Entry.comparingByValue()).getValue();
            ans = Math.min(n - maxCeValue - secondMaxCoValue, n - secondMaxCeValue - maxCoValue);
        }
        System.out.println(ans);
    }
}
// 
