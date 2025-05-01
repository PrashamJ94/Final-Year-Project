import java.util.HashMap;

public class atcoder_ABC124_C {
    public static void main(String[] args) {
        String input = "input_string_here"; // Replace this with the actual input
        char[] s = input.toCharArray();
        HashMap<Character, Integer> even = new HashMap<>();
        HashMap<Character, Integer> odd = new HashMap<>();

        for (int i = 0; i < s.length; i++) {
            if (i % 2 == 0) {
                even.put(s[i], even.getOrDefault(s[i], 0) + 1);
            } else {
                odd.put(s[i], odd.getOrDefault(s[i], 0) + 1);
            }
        }

        int result = Math.min(s.length - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0)),
                s.length - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0)));
        System.out.println(result);
    }
}
// End of Code
