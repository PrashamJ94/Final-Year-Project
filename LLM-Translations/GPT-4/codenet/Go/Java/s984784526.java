public class s984784526 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int[] a = new int[3];

        a[0] = scanner.nextInt();
        a[1] = scanner.nextInt();
        a[2] = scanner.nextInt();

        int five = 0;
        int seven = 0;

        for (int i = 0; i < 3; i++) {
            if (a[i] == 5) {
                five++;
            }
            if (a[i] == 7) {
                seven++;
            }
        }

        if (five == 2 && seven == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
// 
