import java.util.Arrays;
import java.util.Scanner;

public class s430322735 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] lst = new String[n];
        int pair = 0;
        for (int i = 0; i < n; i++) {
            char[] st = sc.next().toCharArray();
            Arrays.sort(st);
            lst[i] = new String(st);
        }
        Arrays.sort(lst);
        lst = Arrays.copyOf(lst, lst.length + 1);
        lst[lst.length - 1] = "end";
        String pre = "";
        int tmp_cnt = 0;
        int cnt = 0;
        for (String i : lst) {
            if (i.equals(pre)) {
                tmp_cnt += 1;
            } else {
                cnt += sum(tmp_cnt + 1);
                tmp_cnt = 0;
            }
            pre = i;
        }
        System.out.println(cnt);
    }

    private static int sum(int n) {
        return n * (n - 1) / 2;
    }
}
// 
