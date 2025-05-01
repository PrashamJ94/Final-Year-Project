import java.util.Scanner;
import java.util.ArrayList;

public class s612033342 {
    public static int pow2(int a) {
        int ret = 1;
        for (int i = 0; i < a; i++) ret *= 2;
        return ret;
    }

    public static int count(ArrayList<ArrayList<Integer>> hw, int a, int b) {
        int sum = 0;
        for (int i = 0; i < hw.size(); i++) {
            for (int j = 0; j < hw.get(0).size(); j++) {
                if (((a >> i) & 1) == 1 && ((b >> j) & 1) == 1 && hw.get(i).get(j) == 1) sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int h = in.nextInt();
        int w = in.nextInt();
        int k = in.nextInt();
        ArrayList<ArrayList<Integer>> hw = new ArrayList<>();
        for (int i = 0; i < h; i++) {
            hw.add(new ArrayList<>());
            for (int j = 0; j < w; j++) {
                char c = in.next().charAt(0);
                if (c == '#') hw.get(i).add(1);
                else hw.get(i).add(0);
            }
        }
        int sum = 0;
        for (int i = 0; i < pow2(h); i++) {
            for (int j = 0; j < pow2(w); j++) {
                if (count(hw, i, j) == k) sum++;
            }
        }
        System.out.println(sum);
    }
}
// 
