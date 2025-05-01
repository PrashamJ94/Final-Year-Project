public class codeforces_59_A {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String txt = scanner.nextLine();
        int cu = 0;
        int cl = 0;
        for (char z : txt.toCharArray()) {
            if (Character.isLowerCase(z)) {
                cl = cl + 1;
            } else {
                cu = cu + 1;
            }
        }
        String out;
        if (cu > cl) {
            out = txt.toUpperCase();
        } else {
            out = txt.toLowerCase();
        }
        System.out.println(out);
    }
}
// End of Code
