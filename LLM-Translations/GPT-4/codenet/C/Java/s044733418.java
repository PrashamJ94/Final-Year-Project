import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s044733418 {
    public static void main(String[] args) {
        Integer[] array = new Integer[10];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        Arrays.sort(array, Comparator.reverseOrder());

        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }
    }
}
// 
