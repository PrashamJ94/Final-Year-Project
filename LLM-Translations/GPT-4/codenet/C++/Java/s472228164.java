public class s472228164 {
    public static String check(int x, int y) {
        if (y % 2 == 0) {
            int t = (int) (0.5 * y) - x;
            if (t >= 0 && (x - t) >= 0)
                return "Yes";
        }
        return "No";
    }

    public static void main(String[] args) {
        int x = 4;
        int y = 6;

        System.out.println(check(x, y));
    }
}
// 
