import java.util.Scanner;

public class s683308527 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        
        while (n-- > 0) {
            String s = sc.nextLine();
            s = s.replaceAll("Hoshino", "Hoshina");
            System.out.println(s);
        }
    }
}
// 
