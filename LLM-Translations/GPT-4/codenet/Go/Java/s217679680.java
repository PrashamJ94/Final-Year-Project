
import java.util.Scanner;
import java.util.Arrays;

public class s217679680 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = scanArrayInt(scanner);
        int a = arr[0], b = arr[1];
        int tap = 0;
        int consent = 1;
        while (consent < b) {
            consent = consent + a - 1;
            tap++;
        }
        System.out.println(tap);
    }

    public static int[] scanArrayInt(Scanner scanner) {
        String[] strArray = scanner.nextLine().split(" ");
        int[] ret = new int[strArray.length];
        for (int i = 0; i < strArray.length; i++) {
            ret[i] = Integer.parseInt(strArray[i]);
        }
        return ret;
    }
}
// 


