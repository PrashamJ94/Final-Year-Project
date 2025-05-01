//java
import java.util.Scanner;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class s086522214 {
    public static void main(String[] args) throws ParseException {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        String[] dateParts = input.split("/");
        
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
        Date currentDate = sdf.parse(input);
        Date heiseiEndDate = sdf.parse("2019/04/30");
        
        if (currentDate.compareTo(heiseiEndDate) <= 0) {
            System.out.println("Heisei");
        } else {
            System.out.println("TBD");
        }
    }
}
// 

