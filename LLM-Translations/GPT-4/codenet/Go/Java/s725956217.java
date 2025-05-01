
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Shop {
    int a, b;

    public Shop(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

public class s725956217 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        Shop[] shops = new Shop[N];

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            shops[i] = new Shop(a, b);
        }

        Arrays.sort(shops, Comparator.comparingInt(o -> o.a));

        int total = 0;
        for (Shop shop : shops) {
            int n = Math.min(shop.b, M);
            total += n * shop.a;
            M -= n;
            if (M == 0) {
                break;
            }
        }

        System.out.println(total);
    }
}

// 
