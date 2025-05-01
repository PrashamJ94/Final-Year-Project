
import java.util.Scanner;

public class codeforces_632_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        String[] input1 = scanner.nextLine().split(" ");
        String[] input2 = scanner.nextLine().split("");
        int[] pieces = new int[input1.length];
        for (int i = 0; i < input1.length; i++) {
            pieces[i] = Integer.parseInt(input1[i]);
        }
        String[] type = input2;
        System.out.println(bobsMaxStrength(pieces, type));
    }

    public static int bobsMaxStrength(int[] pieces, String[] type) {
        int pScore = 0;
        int sScore = 0;
        int pMaxScore = 0;
        int sMaxScore = 0;

        for (int i = 0; i < pieces.length; i++) {
            if (type[i].equals("B")) {
                pScore += pieces[i];
            }
        }
        pMaxScore = sMaxScore = pScore;

        for (int i = 0; i < pieces.length; i++) {
            if (type[i].equals("A")) {
                pScore += pieces[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= pieces[i];
            }
        }

        for (int i = pieces.length - 1; i >= 0; i--) {
            if (type[i].equals("A")) {
                sScore += pieces[i];
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= pieces[i];
            }
        }

        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}

// End of Code
