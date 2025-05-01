
import java.util.*;
import java.io.*;

public class s447383972 {
    static long read(BufferedReader br) throws IOException {
        long x = 0, f = 1;
        char ch = (char) br.read();
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = (char) br.read();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + ch - '0';
            ch = (char) br.read();
        }
        return x * f;
    }

    static void write(long x) {
        if (x < 0) {
            System.out.print('-');
            x = -x;
        }
        if (x >= 10) write(x / 10);
        System.out.print(x % 10);
    }

    static void writeln(long x) {
        write(x);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = read(br);
        long[] a = new long[(int) (n + 1)];
        long[] q = new long[(int) (n + 1)];
        long tot = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = read(br);
        }

        Arrays.sort(a, 1, (int) (n + 1));

        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i + 1]) {
                q[++tot] = a[i];
                i++;
            }
        }

        writeln(q[(int) tot] * q[(int) (tot - 1)]);
    }
}

// 
