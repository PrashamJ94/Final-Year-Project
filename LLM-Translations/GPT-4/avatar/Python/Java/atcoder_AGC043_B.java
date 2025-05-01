public class atcoder_AGC043_B {

    public static int twosInFactorial(int n) {
        return n - Integer.toBinaryString(n).length() - Integer.bitCount(n);
    }

    public static boolean parityOfNCr(int n, int i) {
        int f = twosInFactorial(n) - twosInFactorial(n - i) - twosInFactorial(i);
        return f > 0;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        int[] nums = java.util.Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        boolean noOne = false;
        if (!java.util.Arrays.stream(nums).anyMatch(num -> num == 1)) {
            nums = java.util.Arrays.stream(nums).map(num -> num / 2).toArray();
            noOne = true;
        }
        boolean isOdd = false;
        for (int i = 0; i < nums.length; i++) {
            if (!parityOfNCr(n - 1, i) && (nums[i] & 1) != 0) {
                isOdd = !isOdd;
            }
        }
        if (!isOdd) {
            System.out.println(0);
        } else {
            System.out.println(1 << (noOne ? 1 : 0));
        }
    }
}
// End of Code
