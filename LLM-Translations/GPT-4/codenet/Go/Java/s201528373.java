import java.util.Scanner;
import java.util.ArrayList;

public class s201528373 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        ArrayList<Integer> l = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int tmpL = scanner.nextInt();
            l.add(tmpL);
        }

        int tmpSum = 0;
        int rs = 0;
        for (int i = 0; i < l.size(); i++) {
            tmpSum += l.get(i);
            if (i >= n) {
                rs = n;
                break;
            }
            if (tmpSum <= x) {
                rs = i + 2;
            } else if (tmpSum > x) {
                break;
            }
        }
        System.out.println(rs);
    }
}
// 
