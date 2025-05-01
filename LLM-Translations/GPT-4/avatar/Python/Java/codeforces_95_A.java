import java.util.*;

public class codeforces_95_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pya = scanner.nextInt();
        scanner.nextLine();
        List<String> arre = new ArrayList<>();
        while (pya-- > 0) {
            arre.add(scanner.nextLine().toLowerCase());
        }
        String oString = scanner.nextLine();
        String lowString = oString.toLowerCase();
        String letter1 = scanner.nextLine().toLowerCase().charAt(0) + "";
        String letter2 = letter1.equals("a") ? "b" : "a";
        boolean[] valid = new boolean[oString.length()];
        Set<Integer> setcito = new HashSet<>();
        for (String x : arre) {
            if (lowString.indexOf(x) >= 0) {
                int wat = 0;
                while (true) {
                    int index = lowString.indexOf(x, wat);
                    if (index < 0) {
                        break;
                    }
                    for (int i = index; i < index + x.length(); i++) {
                        setcito.add(i);
                    }
                    wat = index + 1;
                }
            }
        }
        char[] oStringChars = oString.toCharArray();
        for (int i : setcito) {
            String letter = lowString.charAt(i) != letter1.charAt(0) ? letter1 : letter2;
            oStringChars[i] = (oString.charAt(i) >= 'A' && oString.charAt(i) <= 'Z') ? letter.toUpperCase().charAt(0) : letter.charAt(0);
        }
        for (char x : oStringChars) {
            System.out.print(x);
        }
        System.out.println();
    }
}

//End of Code
