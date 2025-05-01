
public class s305455869 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a, b;
        int ans;

        a = scanner.nextInt();
        b = scanner.nextInt();

        ans = 0;
        if (a >= 13) {
            ans = b;
        } else if (a >= 6) {
            ans = b / 2;
        }

        System.out.println(ans);
    }
}

// 
