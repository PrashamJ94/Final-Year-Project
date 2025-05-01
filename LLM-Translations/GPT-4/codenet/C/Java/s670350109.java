
import java.util.Scanner;

public class s670350109 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        sc.close();

        if (str1.length() != str2.length()) {
            System.out.println("NO");
        } else {
            StringBuilder temp = new StringBuilder();
            for (int i = str1.length() - 1; i >= 0; i--) {
                temp.append(str1.charAt(i));
            }

            int t = 0;
            int i = 0;
            while (i < temp.length()) {
                if (temp.charAt(i) == str2.charAt(i)) {
                    t++;
                }
                i++;
            }

            if (str2.length() == t) {
                System.out.println("YES");
            } else if (str2.length() != t) {
                System.out.println("NO");
            }
        }
    }
}

// 
