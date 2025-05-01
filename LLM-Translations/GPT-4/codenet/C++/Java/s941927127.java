
import java.util.Arrays;
import java.util.Scanner;

public class s941927127 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String W = scanner.next();
        
        char[] WArray = W.toCharArray();
        Arrays.sort(WArray);
        boolean isPair = true;
        
        for (int i = 0; i < WArray.length - 1; i += 2) {
            if (WArray[i] != WArray[i + 1]) {
                isPair = false;
                break;
            }
        }
        
        if (isPair) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// 
