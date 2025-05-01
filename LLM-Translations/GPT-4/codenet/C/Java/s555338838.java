
import java.util.Scanner;

public class s555338838 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int key, i, j, len;
        int[] a = new int[101];
        len = sc.nextInt();
        for (i = 0; i < len; i++) a[i] = sc.nextInt();

        for (j = 1; j < len; j++) {
            for (i = 0; i < len; i++) System.out.print((i != 0 ? " " : "") + a[i]);
            System.out.println();
            key = a[j];
            for (i = j - 1; i >= 0 && a[i] > key; i--) a[i + 1] = a[i];
            a[i + 1] = key;
        }

        for (i = 0; i < len; i++) System.out.print((i != 0 ? " " : "") + a[i]);
        System.out.println();
    }
}

// 
