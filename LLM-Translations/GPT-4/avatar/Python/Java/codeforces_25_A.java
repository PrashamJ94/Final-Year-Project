import java.util.Scanner;

public class codeforces_25_A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        String[] input = in.nextLine().split(" ");
        int[] list = new int[n];

        for (int i = 0; i < n; i++) {
            list[i] = Integer.parseInt(input[i]) % 2;
        }

        int sum = 0;
        for (int num : list) {
            sum += num;
        }

        if (sum == 1) {
            System.out.println(findIndex(list, 1) + 1);
        } else {
            System.out.println(findIndex(list, 0) + 1);
        }
    }

    public static int findIndex(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
}
//End of Code
