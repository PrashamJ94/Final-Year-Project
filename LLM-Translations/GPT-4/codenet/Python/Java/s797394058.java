import java.util.ArrayList;
import java.util.Scanner;

public class s797394058 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int x = 1;

        ArrayList<Integer> N_list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            N_list.add(x+i);
        }

        int n = (int) Math.pow(N_list.size(), 3);
        System.out.println(n);
    }
}
// 
