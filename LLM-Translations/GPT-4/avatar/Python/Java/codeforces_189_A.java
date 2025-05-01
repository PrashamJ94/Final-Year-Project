public class codeforces_189_A {
    public static void main(String[] args) {
        int[] arr = {3, 5, 7}; // Replace with input values
        int length = arr[0];
        int[] sortedArr = Arrays.copyOfRange(arr, 1, 4);
        Arrays.sort(sortedArr);

        if (length % sortedArr[0] == 0) {
            System.out.println(length / sortedArr[0]);
            return;
        }

        int ans = 0;
        if (sortedArr[0] == sortedArr[1]) {
            int k = 0;
            for (int i = 0; i <= length / sortedArr[2]; i++) {
                int check = length - i * sortedArr[2];
                if (check >= 0 && check % sortedArr[0] == 0) {
                    k = check / sortedArr[0];
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            int k = 0;
            for (int i = 0; i <= length / sortedArr[2]; i++) {
                for (int j = 0; j <= length / sortedArr[1]; j++) {
                    int check = length - i * sortedArr[2] - j * sortedArr[1];
                    if (check >= 0 && check % sortedArr[0] == 0) {
                        k = check / sortedArr[0];
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
// End of Code
