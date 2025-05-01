import java.util.*;

public class s331817031 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        sc.nextLine();
        List<String> l = new ArrayList<>();
        
        for (int i = 0; i < h; i++) {
            l.add(sc.nextLine());
        }

        int tmp = 0;
        boolean flag = true;

        outerLoop:
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (l.get(i).charAt(j) == '#') {
                    if (j < tmp) {
                        System.out.println("Impossible");
                        flag = false;
                        break outerLoop;
                    } else {
                        tmp = j;
                    }
                }
            }
        }

        if(flag) {
            System.out.println("Possible");
        }
    }
}
// 
