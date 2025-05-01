import java.util.Scanner;

public class s992866158 {
    public static void main(String[] args) {
        int n, k, cnt;

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        cnt = 0;
        while (n-- > 0) {
            int h;

            h = sc.nextInt();
            if (h >= k)
                cnt++;
        }
        System.out.println(cnt);
    }
}
// 
