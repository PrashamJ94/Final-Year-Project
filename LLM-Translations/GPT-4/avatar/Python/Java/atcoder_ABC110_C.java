import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class atcoder_ABC110_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(run(s, t));
    }

    public static String run(String s, String t) {
        int[] ss = sortedFrequencyCount(s);
        int[] tt = sortedFrequencyCount(t);
        if (Arrays.equals(ss, tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }

    public static int[] sortedFrequencyCount(String s) {
        HashMap<Character, Integer> counter = new HashMap<>();
        for (char c : s.toCharArray()) {
            counter.put(c, counter.getOrDefault(c, 0) + 1);
        }
        int[] sortedValues = counter.values().stream().mapToInt(Integer::intValue).toArray();
        Arrays.sort(sortedValues);
        return sortedValues;
    }
}
// End of Code.
