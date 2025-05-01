
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Point {
    int x, l, r;

    Point(int x, int l, int r) {
        this.x = x;
        this.l = l;
        this.r = r;
    }
}

public class s252511058 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Point[] points = new Point[N];

        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int L = sc.nextInt();
            points[i] = new Point(x, x - L, x + L);
        }

        Arrays.sort(points, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                return Integer.compare(p1.r, p2.r);
            }
        });

        int start = points[0].r;
        int ans = 1;
        for (int i = 0; i < points.length; i++) {
            if (points[i].l < start) {
                continue;
            }
            start = points[i].r;
            ans++;
        }

        System.out.println(ans);
    }
}


