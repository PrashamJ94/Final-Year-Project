import java.util.Scanner;

public class s141943854 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sage = Integer.parseInt(scanner.nextLine());

        switch (sage) {
            case 1:
                System.out.println("Hello World");
                break;
            case 2:
                int sum = 0;
                for (int i = 0; i < 2; i++) {
                    int num = Integer.parseInt(scanner.nextLine());
                    sum += num;
                }
                System.out.println(sum);
                break;
        }
    }
}
// 
