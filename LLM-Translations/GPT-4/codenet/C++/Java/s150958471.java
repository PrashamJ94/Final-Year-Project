import java.util.Scanner;

public class s150958471 {
    public static void main(String[] args) {
        int[] train = new int[2];
        int[] bus = new int[2];

        Scanner in = new Scanner(System.in);

        train[0] = in.nextInt();
        train[1] = in.nextInt();
        bus[0] = in.nextInt();
        bus[1] = in.nextInt();

        System.out.println(Math.min(train[0], train[1]) + Math.min(bus[0], bus[1]));

        in.close();
    }
}
// 
