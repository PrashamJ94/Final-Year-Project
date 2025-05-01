
import java.util.Arrays;
import java.util.Scanner;

public class s065149518 {

    private static final int MAX = 21;
    private static int n, x, y;
    private static char[][] fld = new char[MAX][MAX];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            init(n);
            int m = scanner.nextInt();
            move(m);
            System.out.println(n == 0 ? "Yes" : "No");
        }
    }

    private static void init(int i) {
        int a, b;
        x = y = 10;
        for (char[] row : fld) {
            Arrays.fill(row, (char) 0);
        }
        while (i-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    private static void move(int i) {
        int a, d;
        String buf;
        while (i-- > 0) {
            buf = scanner.next();
            a = scanner.nextInt();

            switch (buf.charAt(0)) {
                case 'N':
                    d = 0;
                    break;
                case 'E':
                    d = 1;
                    break;
                case 'S':
                    d = 2;
                    break;
                case 'W':
                    d = 3;
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + buf.charAt(0));
            }

            while (a-- > 0) {
                if (d % 2 == 0) {
                    if (d == 0) {
                        y++;
                    } else {
                        y--;
                    }
                } else {
                    if (d == 1) {
                        x++;
                    } else {
                        x--;
                    }
                }

                if (fld[y][x] == 1) {
                    fld[y][x] = 0;
                    n--;
                }
            }
        }
    }
}
// 

