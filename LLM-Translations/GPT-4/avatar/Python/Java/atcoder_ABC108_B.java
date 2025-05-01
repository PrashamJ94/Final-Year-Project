public class atcoder_ABC108_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        int x1 = Integer.parseInt(input[0]);
        int y1 = Integer.parseInt(input[1]);
        int x2 = Integer.parseInt(input[2]);
        int y2 = Integer.parseInt(input[3]);
        
        int DIF1 = x2 - x1;
        int DIF2 = y2 - y1;
        
        int x3 = x2 - DIF2;
        int y3 = y2 + DIF1;
        int x4 = x1 - DIF2;
        int y4 = y1 + DIF1;
        
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}
// End of Code
