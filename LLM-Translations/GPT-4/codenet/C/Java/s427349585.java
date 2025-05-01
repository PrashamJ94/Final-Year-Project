import java.util.Scanner;

class Card {
    char s;
    int v;

    Card(char s, int v) {
        this.s = s;
        this.v = v;
    }
}

public class s427349585 {
    static Card[] L = new Card[100000 / 2 + 2];
    static Card[] R = new Card[100000 / 2 + 2];

    static void merge(Card[] a, int n, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l;
        int n2 = r - m;

        for (i = 0; i < n1; i++) L[i] = a[l + i];
        for (i = 0; i < n2; i++) R[i] = a[m + i];
        L[n1] = new Card('\0', 2000000000);
        R[n2] = new Card('\0', 2000000000);
        i = 0;
        j = 0;
        for (k = l; k < r; k++) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
        }
    }

    static void mergeSort(Card[] a, int n, int l, int r) {
        int m;
        if (l + 1 < r) {
            m = (l + r) / 2;
            mergeSort(a, n, l, m);
            mergeSort(a, n, m, r);
            merge(a, n, l, m, r);
        }
    }

    static int partition(Card[] a, int n, int p, int r) {
        int i, j;
        Card t, x;
        x = a[r];
        i = p - 1;
        for (j = p; j < r; j++) {
            if (a[j].v <= x.v) {
                i++;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        t = a[i + 1];
        a[i + 1] = a[r];
        a[r] = t;
        return i + 1;
    }

    static void quickSort(Card[] a, int n, int p, int r) {
        int q;

        if (p < r) {
            q = partition(a, n, p, r);
            quickSort(a, n, p, q - 1);
            quickSort(a, n, q + 1, r);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, i, v;
        Card[] a = new Card[200000];
        Card[] b = new Card[200000];
        String s;
        boolean stable = true;

        n = sc.nextInt();

        for (i = 0; i < n; i++) {
            s = sc.next();
            v = sc.nextInt();
            a[i] = b[i] = new Card(s.charAt(0), v);
        }

        mergeSort(a, n, 0, n);
        quickSort(b, n, 0, n - 1);

        for (i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
                stable = false;
            }
        }
        if (stable) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }
        for (i = 0; i < n; i++) {
            System.out.printf("%c %d\n", b[i].s, b[i].v);
        }

        sc.close();
    }
}
// 
