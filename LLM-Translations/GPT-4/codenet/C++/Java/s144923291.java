import java.io.*;
import java.util.*;
import java.math.*;

public class s144923291 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String[][] arr = new String[h][w];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                arr[i][j] = sc.next();
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j].equals("snuke")) {
                    char c = (char) ('A' + j);
                    System.out.println(c + "" + (i + 1));
                    return;
                }
            }
        }
    }
}
// 
