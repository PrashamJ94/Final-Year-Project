
import java.util.*;

public class s557024716 {
    static int a, b, c, k;
    static List<List<Integer>> patterns;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        k = sc.nextInt();
        
        patterns = duplicatePatterns(Arrays.asList(0, 1, 2, 3), k);
        
        for (List<Integer> P : patterns) {
            int r = a, g = b, bl = c;
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue;
                } else if (P.get(i) == 1) {
                    r *= 2;
                } else if (P.get(i) == 2) {
                    g *= 2;
                } else if (P.get(i) == 3) {
                    bl *= 2;
                }
            }
            
            if (g > r && bl > g) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
    
    public static List<List<Integer>> duplicatePatterns(List<Integer> elems, int k) {
        return dupliRec(new ArrayList<>(), elems, k);
    }
    
    public static List<List<Integer>> dupliRec(List<Integer> pattern, List<Integer> elems, int k) {
        if (pattern.size() == k) {
            List<List<Integer>> res = new ArrayList<>();
            res.add(pattern);
            return res;
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern);
            newPattern.add(e);
            res.addAll(dupliRec(newPattern, elems, k));
        }

        return res;
    }
}


