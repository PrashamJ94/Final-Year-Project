
public class s134607050 {
    public static void main(String[] args) {
        answer();
    }

    public static int[] searchRange(String text, int start, int limit) {
        int middle = -1;

        for (int i = start; i < limit; i++) {
            if (text.charAt(i) != 'R') {
                middle = i;
                break;
            }
        }

        int end = limit;

        for (int i = middle; i < limit; i++) {
            if (text.charAt(i) != 'L') {
                end = i;
                break;
            }
        }

        return new int[]{start, middle, end};
    }

    public static void answer() {
        String text = new java.util.Scanner(System.in).next();
        int limit = text.length();

        int start = 0;
        int middle = 0;
        int end = 0;
        boolean firstPrinted = false;

        while (end < limit) {
            int[] result = searchRange(text, start, limit);
            start = result[0];
            middle = result[1];
            end = result[2];
            int len1 = middle - start;
            int len2 = end - middle;

            for (int i = start; i < middle - 1; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }

            int count1 = (len1 + 1) / 2 + len2 / 2;
            int count2 = len1 / 2 + (len2 + 1) / 2;

            if (firstPrinted) {
                System.out.print(" ");
            }
            System.out.printf("%d %d", count1, count2);
            firstPrinted = true;

            for (int i = middle + 1; i < end; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }
            start = end;
            firstPrinted = true;
        }
        System.out.println();
    }
}


