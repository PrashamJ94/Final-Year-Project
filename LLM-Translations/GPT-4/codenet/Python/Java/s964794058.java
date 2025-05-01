import java.util.ArrayList;
import java.util.Scanner;

public class s964794058 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int memTime = sc.nextInt();
        sc.nextLine();
        String[] input = sc.nextLine().split(" ");
        ArrayList<Integer> memLate = new ArrayList<>();
        for (String s : input) {
            memLate.add(Integer.parseInt(s));
        }
        ArrayList<Integer> colorList = new ArrayList<>();
        int memColor = 0;
        int highLate = 0;
        for (int color = 0; color < memTime; color++) {
            int member = memLate.get(color);
            if (member / 400 >= 8) {
                highLate++;
            } else if (!colorList.contains(member / 400)) {
                colorList.add(member / 400);
            }
        }
        int maxColor = colorList.size() + highLate;
        int minColor = colorList.size();
        if (minColor == 0) {
            minColor = 1;
        }
        System.out.println(minColor + " " + maxColor);
    }
}
// 
