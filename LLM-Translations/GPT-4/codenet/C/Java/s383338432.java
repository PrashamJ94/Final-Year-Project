public class s383338432 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int height = scanner.nextInt();
        int width = scanner.nextInt();
        scanner.nextLine(); // To consume the newline character
        String inputStr;
        
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
        
        for (int i = 0; i < height; i++) {
            inputStr = scanner.nextLine();
            System.out.println("#" + inputStr + "#");
        }
        
        for (int i = 0; i < width + 2; i++) {
            System.out.print("#");
        }
        System.out.println();
        
        scanner.close();
    }
}
// 
