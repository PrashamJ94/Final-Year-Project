public class s585881557 {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        
        int h = input.nextInt();
        int r = input.nextInt();
        input.close();

        if (r > -h) {
            System.out.println("1");
        } else if (r == -h) {
            System.out.println("0");
        } else {
            System.out.println("-1");
        }
    }
}
// 
