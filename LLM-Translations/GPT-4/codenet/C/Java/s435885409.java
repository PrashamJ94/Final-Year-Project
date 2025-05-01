import java.util.Scanner;

public class s435885409 {
    
    public static int calc_score(Scanner scanner) {
        int out = 0;
        String str;
        int score = 0;
        int base = 0;

        while (out < 3) {
            str = scanner.next();
            if (str.equals("OUT")) {
                out++;
            } else if (str.equals("HIT")) {
                if (base == 3) {
                    score++;
                } else {
                    base++;
                }
            } else if (str.equals("HOMERUN")) {
                score += (base + 1);
                base = 0;
            }
        }

        return score;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int inning = 0;

        n = scanner.nextInt();

        while (inning < n) {
            System.out.println(calc_score(scanner));
            inning++;
        }

        scanner.close();
    }
}
// 
