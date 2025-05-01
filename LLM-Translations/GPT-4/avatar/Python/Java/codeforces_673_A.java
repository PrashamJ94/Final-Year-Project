
import java.util.Scanner;

public class codeforces_673_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        if (arr[0] > 15) {
            System.out.println(15);
        } else {
            boolean found = false;
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] - arr[i - 1] > 15) {
                    System.out.println(arr[i - 1] + 15);
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (arr[arr.length - 1] == 90 || arr[arr.length - 1] + 15 >= 90) {
                    System.out.println(90);
                } else {
                    System.out.println(arr[arr.length - 1] + 15);
                }
            }
        }
    }
}

// End of Code
