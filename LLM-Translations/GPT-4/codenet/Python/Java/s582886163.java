import java.util.Arrays;
import java.util.Scanner;

public class s582886163 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] capacityList = new int[5];
        for (int i = 0; i < 5; i++) {
            capacityList[i] = scanner.nextInt();
        }
        Arrays.sort(capacityList);
        int bottleNeck = capacityList[0];
        System.out.println(4 + (int) ((N + bottleNeck - 1) / bottleNeck));
    }
}
// 
