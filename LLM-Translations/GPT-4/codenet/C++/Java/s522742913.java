import java.util.Scanner;

public class s522742913 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String source = sc.next();
        sc.close();

        if (source.length() > 10 || source.length() < 1) {
            return;
        }

        int max_i = (int) Math.pow(2, source.length() - 1);

        double sum = 0;

        for (int i = 0; i < max_i; ++i) {
            int plus = i;
            double number = 0;

            String working = source;
            while (plus != 0) {
                int index = 0;
                while ((plus & (1 << index)) == 0) {
                    ++index;
                }
                sum += Double.parseDouble(working.substring(0, index + 1));
                plus >>= index + 1;
                working = working.substring(index + 1);
            }
            sum += Double.parseDouble(working);
        }

        System.out.printf("%.0f%n", sum);
    }
}

// 
