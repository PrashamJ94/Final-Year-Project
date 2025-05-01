public class codeforces_222_A {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = sc.nextInt();
        }

        if (allSame(elems)) {
            System.out.println(0);
            return;
        }
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        if (!allSame(java.util.Arrays.copyOfRange(elems, k - 1, elems.length))) {
            System.out.println(-1);
            return;
        }
        
        int target = elems[elems.length - 1];
        int[] toDelete = java.util.Arrays.copyOfRange(elems, 0, k - 1);
        int count = toDelete.length;
        while (count > 0 && toDelete[count - 1] == target) {
            count--;
        }
        System.out.println(count);
    }

    public static boolean allSame(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[0]) {
                return false;
            }
        }
        return true;
    }
}
// End of Code
