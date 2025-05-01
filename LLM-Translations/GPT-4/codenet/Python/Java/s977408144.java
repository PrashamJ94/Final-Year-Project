import java.util.Arrays;
import java.util.Scanner;

public class s977408144 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        sc.nextLine();
        String[] S = new String[n];
        for (int a = 0; a < n; a++) {
            S[a] = sc.nextLine();
        }
        Arrays.sort(S);
        StringBuilder sb = new StringBuilder();
        for (String s : S) {
            sb.append(s);
        }
        System.out.println(sb.toString());
    }
}
// 
