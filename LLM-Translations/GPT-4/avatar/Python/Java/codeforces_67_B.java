import java.util.Scanner;

public class codeforces_67_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine();
        
        int[] M = new int[n];
        for(int i=0; i<n; i++) {
            M[i] = scanner.nextInt();
        }
        
        for(int j=0; j<n; j++) {
            int p = 0;
            for(p=0; p<n; p++) {
                if(M[p] == 0) {
                    System.out.print(p + 1 + " ");
                    break;
                }
            }
            
            for(int l=0; l<p+1-k; l++) {
                M[l] -= 1;
            }
            
            M[p] -= 1;
        }
    }
}

// End of Code
