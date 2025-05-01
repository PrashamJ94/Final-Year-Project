import java.util.Arrays;
import java.util.Scanner;

public class s240156356 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.next();
        String str2 = scanner.next();
        scanner.close();

        char[] str1Array = str1.toCharArray();
        char[] str2Array = str2.toCharArray();

        Arrays.sort(str1Array);
        Arrays.sort(str2Array);
        for (int i = 0; i < str2Array.length / 2; i++) {
            char temp = str2Array[i];
            str2Array[i] = str2Array[str2Array.length - 1 - i];
            str2Array[str2Array.length - 1 - i] = temp;
        }

        int loop = str1.length() > str2.length() ? str2.length() : str1.length();
        boolean flag = false;

        for(int i = 0; loop > i; i++){
            char ch1 = str1Array[i];
            char ch2 = str2Array[i];

            if(ch1 == ch2){
                if(loop == i + 1 && str1.length() < str2.length()){
                    flag = true;
                    break;
                }else{
                    continue;
                }
            }else{
                if(ch2 > ch1){
                    flag = true;
                    break;
                }else{
                    break;
                }
            }
        }

        if(flag){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
// 
