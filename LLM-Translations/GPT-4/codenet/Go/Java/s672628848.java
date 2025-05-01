public class s672628848 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int[] al = new int[5];
        
        for (int i = 0; i < 5; i++) {
            al[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < al.length; i++) {
            if (al[i] == 0) {
                System.out.println(i + 1);
                break;
            }
        }
    }
}
// 
