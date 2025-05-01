import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class atcoder_ABC150_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        int[] p = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] q = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        List<int[]> permutations = generatePermutations(IntStream.rangeClosed(1, n).toArray());
        int indexP = indexOf(permutations, p);
        int indexQ = indexOf(permutations, q);
        System.out.println(Math.abs(indexP - indexQ));
    }

    public static List<int[]> generatePermutations(int[] array) {
        List<int[]> permutations = new java.util.ArrayList<>();
        permutation(array, 0, permutations);
        return permutations;
    }

    private static void permutation(int[] arr, int pos, List<int[]> list) {
        if (pos == arr.length) {
            list.add(arr.clone());
        } else {
            for (int i = pos; i < arr.length; i++) {
                swap(arr, pos, i);
                permutation(arr, pos + 1, list);
                swap(arr, pos, i);
            }
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int indexOf(List<int[]> list, int[] target) {
        for (int i = 0; i < list.size(); i++) {
            if (Arrays.equals(list.get(i), target)) {
                return i;
            }
        }
        return -1;
    }
}
// End of Code
