
import java.util.Scanner;

public class s864554008 {
    public static void main(String[] args) {
        Data d = newData();
        if (d.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static Data newData() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String[] nImg = load(scanner, n);
        String[] mImg = load(scanner, m);
        return new Data(n, m, nImg, mImg);
    }

    private static String[] load(Scanner scanner, int cnt) {
        String[] ret = new String[cnt];
        for (int i = 0; i < cnt; i++) {
            ret[i] = scanner.next();
        }
        return ret;
    }
}

class Data {
    int n, m;
    String[] nImg, mImg;

    Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    boolean exist() {
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (match(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    boolean match(int x, int y) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (nImg[x + i].charAt(y + j) != mImg[i].charAt(j)) {
                    return false;
                }
            }
        }
        return true;
    }
}


