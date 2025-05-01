import java.util.Arrays;
import java.util.ArrayList;

public class atcoder_AGC021_B {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int[] XY = new int[args.length - 1];
        for (int i = 1; i < args.length; i++) {
            XY[i - 1] = Integer.parseInt(args[i]);
        }

        ArrayList<int[]> coordinates = new ArrayList<>();
        for (int i = 0; i < XY.length; i += 2) {
            coordinates.add(new int[]{XY[i], XY[i + 1]});
        }

        for (int i = 0; i < coordinates.size(); i++) {
            int[] a = coordinates.get(i);
            double[] angles = new double[coordinates.size() - 1];
            int index = 0;
            for (int j = 0; j < coordinates.size(); j++) {
                if (j != i) {
                    int[] b = coordinates.get(j);
                    angles[index++] = Math.atan2(b[0] - a[0], b[1] - a[1]);
                }
            }
            Arrays.sort(angles);
            double[] extendedAngles = Arrays.copyOf(angles, angles.length + 1);
            extendedAngles[angles.length] = extendedAngles[0] + 2 * Math.PI;
            double ans = 0;
            for (int k = 0; k < extendedAngles.length - 1; k++) {
                if (extendedAngles[k + 1] - extendedAngles[k] >= Math.PI) {
                    ans = (extendedAngles[k + 1] - extendedAngles[k]) - Math.PI;
                }
            }
            System.out.println(ans / (2 * Math.PI));
        }
    }
}
// End of Code
