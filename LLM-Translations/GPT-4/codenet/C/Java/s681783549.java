
import java.util.Scanner;

public class s681783549 {
    public static void main(String[] args) {
        int i;
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        char[] SArray = S.toCharArray();
        
        for (i = 0; i < SArray.length - 1; i++) {
            if (SArray[i] == 'A' && SArray[i + 1] == 'C') {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}

// 
