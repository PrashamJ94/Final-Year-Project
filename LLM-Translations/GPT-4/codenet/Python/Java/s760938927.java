import java.util.Scanner;

public class s760938927 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int ka = scanner.nextInt();
        scanner.nextLine();

        char[][] mat = new char[h][w];
        for (int i = 0; i < h; i++) {
            mat[i] = scanner.nextLine().toCharArray();
        }
        int ans = 0;
        for (int i = 0; i < (1 << (h + w)); i++) {
            String b = Integer.toBinaryString(i);
            b = String.format("%" + (h + w) + "s", b).replace(' ', '0');
            String rs = b.substring(0, h);
            String cs = b.substring(h);
            int ct = 0;
            for (int l = 0; l < h; l++) {
                for (int k = 0; k < w; k++) {
                    if (mat[l][k] == '#' && rs.charAt(l) == '0' && cs.charAt(k) == '0') {
                        ct++;
                    }
                }
            }
            if (ct == ka) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
// 
