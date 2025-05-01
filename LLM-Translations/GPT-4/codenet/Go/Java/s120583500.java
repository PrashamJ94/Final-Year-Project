import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class s120583500 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int count = 0;
        ArrayList<Integer> counter = new ArrayList<>();

        if (s.equals("")) {
            return;
        }
        counter.add(0);
        String[] li = s.split("");

        for (String element : li) {
            if (element.equals("A") || element.equals("C") || element.equals("G") || element.equals("T")) {
                count++;
            } else {
                counter.add(count);
                count = 0;
            }
        }

        counter.add(count);
        Collections.sort(counter);
        System.out.println(counter.get(counter.size() - 1));
    }
}
// 
