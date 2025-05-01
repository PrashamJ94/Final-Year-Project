import java.util.*;
import java.io.*;

public class atcoder_ABC112_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int[][] ls_xyh = new int[n][3];
        for (int i = 0; i < n; i++) {
            String[] data = br.readLine().trim().split("\\s+");
            ls_xyh[i][0] = Integer.parseInt(data[0]);
            ls_xyh[i][1] = Integer.parseInt(data[1]);
            ls_xyh[i][2] = Integer.parseInt(data[2]);
        }
        System.out.println(solve(n, ls_xyh));
    }

    public static String solve(int n, int[][] ls_xyh) {
        int x0 = 0, y0 = 0, h0 = 0;
        for (int i = 0; i < n; i++) {
            if (ls_xyh[i][2] > 0) {
                x0 = ls_xyh[i][0];
                y0 = ls_xyh[i][1];
                h0 = ls_xyh[i][2];
                break;
            }
        }
        ArrayList<int[]> cands = new ArrayList<>();
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                cands.add(new int[]{cx, cy, h0 + Math.abs(cx - x0) + Math.abs(cy - y0)});
            }
        }
        for (int[] xyh : ls_xyh) {
            int x = xyh[0];
            int y = xyh[1];
            int h = xyh[2];
            cands.removeIf(candidate -> Math.max(candidate[2] - Math.abs(candidate[0] - x) - Math.abs(candidate[1] - y), 0) != h);
        }
        int[] result = cands.get(0);
        return result[0] + " " + result[1] + " " + result[2];
    }
}
// End of Code.
