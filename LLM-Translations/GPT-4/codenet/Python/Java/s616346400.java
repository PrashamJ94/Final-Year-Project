public class s616346400 {
    public static String atc_079a(String input_value) {
        int n = 3;
        for (int i = 0; i < input_value.length() + 1 - n; i++) {
            for (int j = 1; j < n; j++) {
                if (input_value.charAt(i) != input_value.charAt(i + j)) {
                    break;
                }
                if (j == n - 1) {
                    return "Yes";
                }
            }
        }
        return "No";
    }

    public static void main(String[] args) {
        String input_value = "1233";
        System.out.println(atc_079a(input_value));
    }
}
// 
