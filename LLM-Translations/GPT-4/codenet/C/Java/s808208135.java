import java.util.Scanner;

class Date {
    int go, back, cost;
}

public class s808208135 {
    static int N = 100000;
    static int INF = 1000000;
    static int n;
    static int[] d = new int[N];
    static Date[] a = new Date[500000];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int u = in.nextInt();
            int k = in.nextInt();
            for (int j = 0; j < k; j++) {
                a[count] = new Date();
                a[count].back = u;
                a[count].go = in.nextInt();
                a[count].cost = in.nextInt();
                count++;
            }
        }
        root(count);
        for (int i = 0; i < n; i++)
            System.out.println(i + " " + d[i]);
    }

    public static void root(int b) {
        int flag = 1;

        for (int i = 0; i < n; i++)
            d[i] = INF;
        d[0] = 0;

        while (flag != 0) {
            flag = 0;
            for (int i = 0; i < b; i++) {
                if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                    d[a[i].go] = a[i].cost + d[a[i].back];
                    flag = 1;
                }
            }
        }
    }
}
// 
