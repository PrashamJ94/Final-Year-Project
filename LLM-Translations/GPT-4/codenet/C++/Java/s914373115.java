import java.util.Scanner;

public class s914373115 {
    public static void main(String[] args) {
        B();
    }

    public static void B() {
        long x, sum;
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextLong();
        int i;
        sum = 100;
        for (i = 0; sum < x; ++i) {
            sum += sum / 100;
        }
        System.out.println(i);
    }
}
// 
