import java.util.Scanner;

public class s503150457 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();
        String s3 = scanner.next();

        char s1First = Character.toUpperCase(s1.charAt(0));
        char s2First = Character.toUpperCase(s2.charAt(0));
        char s3First = Character.toUpperCase(s3.charAt(0));

        System.out.println(s1First + "" + s2First + "" + s3First);
    }
}

// 
