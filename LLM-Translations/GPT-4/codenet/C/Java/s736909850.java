public class s736909850 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int sheep = scanner.nextInt();
        int wolf = scanner.nextInt();
        scanner.close();

        if (wolf >= sheep) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}
// 
