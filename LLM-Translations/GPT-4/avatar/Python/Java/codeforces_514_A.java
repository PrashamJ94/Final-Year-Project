
import java.util.Scanner;

public class codeforces_514_A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String ip = input.nextLine();
        String st = "";

        if (ip.length() != 1) {
            if (ip.charAt(0) == '9') {
                st = "9";
                ip = ip.substring(1);
            }
            for (char i : ip.toCharArray()) {
                int num = Character.getNumericValue(i);
                if (num > 4) {
                    int n = 9 - num;
                    st += Integer.toString(n);
                } else {
                    st += i;
                }
            }
        } else {
            st = ip;
        }
        System.out.println(Integer.parseInt(st));
    }
}

// End of Code
