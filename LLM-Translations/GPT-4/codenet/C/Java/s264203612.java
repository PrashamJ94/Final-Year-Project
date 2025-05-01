public class s264203612 {
    public static void main(String[] args) {
        double r;
        double s, l;
        double p = 3.141592653589;
        java.util.Scanner input = new java.util.Scanner(System.in);
        
        r = input.nextDouble();
        
        s = r * r * p;
        l = 2 * p * r;
        
        System.out.printf("%f %f\n", s, l);
        
        input.close();
    }
}
// 
