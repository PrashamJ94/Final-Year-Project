import java.util.*;
import java.math.*;

public class atcoder_ABC150_D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = sc.nextInt();
        sc.nextLine();
        String[] input = sc.nextLine().split(" ");

        HashSet<Integer> num_set = new HashSet<>();
        for (String s : input) {
            num_set.add(Integer.parseInt(s));
        }

        HashSet<Integer> two_times_set = new HashSet<>();
        for (int i : num_set) {
            for (int j = 1; j < 30; j++) {
                i /= 2;
                if (i % 2 != 0) {
                    two_times_set.add(j);
                    break;
                }
            }
            if (two_times_set.size() != 1) {
                System.out.println(0);
                break;
            }
        }

        if (two_times_set.size() == 1) {
            ArrayList<Integer> num_list = new ArrayList<>(num_set);
            int lcm = num_list.get(0);
            for (int i = 1; i < num_list.size(); i++) {
                lcm = lcm * num_list.get(i) / BigInteger.valueOf(lcm).gcd(BigInteger.valueOf(num_list.get(i))).intValue();
            }
            System.out.println((num - lcm / 2) / lcm + 1);
        }
    }
}
// End of Code
