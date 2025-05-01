public class s343830814 {
    public static void main(String[] args) {
        java.io.BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        String input = "";
        try {
            input = reader.readLine();
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
        int len = input.length();
        System.out.printf("%c%d%c%n", input.charAt(0), len - 3, input.charAt(len - 2));
    }
}
// 
