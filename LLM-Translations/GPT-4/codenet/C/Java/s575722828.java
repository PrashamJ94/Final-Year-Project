public class s575722828 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int S = sc.nextInt();
        sc.close();

        int hours = S / 3600;
        int minutes = (S % 3600) / 60;
        int seconds = S % 60;

        System.out.printf("%d:%d:%d\n", hours, minutes, seconds);
    }
}
// 
