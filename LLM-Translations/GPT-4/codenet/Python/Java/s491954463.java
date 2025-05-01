import java.util.*;

public class s491954463 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }
        
        for (int i = 1; i <= n; i++) {
            System.out.println(countOccurrences(a, i) + countOccurrences(b, i));
        }
    }
    
    private static int countOccurrences(int[] arr, int num) {
        int count = 0;
        for (int i : arr) {
            if (i == num) {
                count++;
            }
        }
        return count;
    }
}
// 
