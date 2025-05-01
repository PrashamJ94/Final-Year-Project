import java.util.Scanner;

public class s097779718 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long A = in.nextLong();
        long B = in.nextLong();
        in.close();

        System.out.println((A * B) / Euclid(A, B));
    }

    public static long Euclid(long x, long y) {
        long tmp;

        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        if (x % y == 0) return y;
        return Euclid(y, x % y);
    }
}
// 
