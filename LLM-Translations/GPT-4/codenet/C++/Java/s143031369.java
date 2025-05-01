
import java.util.*;
import static java.lang.Math.*;

public class s143031369 {
    static final double EPS = 1e-8;
    static int sig(double d) {
        return Math.abs(d) < EPS ? 0 : d < 0 ? -1 : 1;
    }

    static class Point {
        double x, y;
        Point() {}
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
        void set(double x, double y) {
            this.x = x;
            this.y = y;
        }
        double mod() {
            return Math.sqrt(x * x + y * y);
        }
        boolean less(Point p) {
            return sig(x - p.x) != 0 ? x < p.x : sig(y - p.y) < 0;
        }
    }

    static double dot(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
    }

    static double dis(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    static double cos(Point o, Point a, Point b) {
        return dot(o, a, b) / dis(o, a) / dis(o, b);
    }

    static int jarvis(Point[] p, int n, int[] ch) {
        int d = 0, i, o, s, l, t;
        for (i = 0; i < n; i++)
            if (p[i].less(p[d]))
                d = i;
        l = s = ch[0] = d;
        d = 1;
        do {
            o = l;
            for (i = 0; i < n; i++)
                if ((t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0))
                    l = i;
            ch[d++] = l;
        } while (l != s);
        return d - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Point[] P = new Point[n];
        for (int i = 0; i < n; i++) {
            P[i] = new Point(sc.nextDouble(), sc.nextDouble());
        }
        int[] ch = new int[n];
        double[] ang = new double[n], ans = new double[n];
        int m = jarvis(P, n, ch);
        double sum = 0;
        if (m == 2) {
            ans[ch[0]] = 0.5;
            ans[ch[1]] = 0.5;
        } else {
            for (int i = 0; i < m; i++) {
                ang[ch[i]] = PI - acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
            }
            for (int i = 0; i < n; i++) {
                ans[i] = ang[i] / 2.0 / PI;
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.printf("%.20f\n", ans[i]);
        }
    }
}

// 
