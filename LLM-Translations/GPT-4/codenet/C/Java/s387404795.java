
public class s387404795 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.next();
        String p = scanner.next();

        str = str.concat(str.substring(0, str.length() - 1));

        boolean flag = false;
        for (int i = 0; i < str.length() - p.length(); i++) {
            if (str.substring(i, i + p.length()).equals(p)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// 
