import java.util.Scanner;
import java.util.ArrayList;

public class s107204188 {
    public static void main(String[] args) {
        int minA = (int)Math.pow(10, 9) + 1;
        int num = 0;

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        ArrayList<Integer> A = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            A.add(scanner.nextInt());
        }

        int f = 0;
        for (int i = 0; i < n; i++) {
            if (minA > A.get(i)) {
                minA = A.get(i);
            } else {

                if (f == A.get(i) - minA) num++;
                else if (f < A.get(i) - minA) {
                    num = 1;
                    f = A.get(i) - minA;
                }
            }
        }

        System.out.println(num);

        scanner.close();
    }
}
// 
