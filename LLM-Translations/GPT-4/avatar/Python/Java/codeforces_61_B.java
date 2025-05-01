import java.util.*;
import java.lang.*;
import java.io.*;

public class codeforces_61_B {
{
    public static boolean valid(int i, int j, int n, int m) {
        if (i < n && i >= 0 && j >= 0 && j < m) return true;
        return false;
    }
    
    public static int sumn(int i, int n) {
        return (int)((n - i) * (i + n) / 2);
    }
    
    public static double sqfun(int a, int b, int c) {
        return (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
    }
    
    public static String f(String s) {
        String r = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != '-' && c != ';' && c != '_') r += Character.toLowerCase(c);
        }
        return r;
    }
    
    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> l = new ArrayList<String>();
        for (int i = 0; i < 3; i++) {
            l.add(f(scanner.nextLine()));
        }
        
        List<List<String>> t = new ArrayList<List<String>>();
        Permutations.permute(l, t);
        
        ArrayList<String> l1 = new ArrayList<String>();
        for (List<String> sublist : t) {
            l1.add(String.join("", sublist));
        }
        
        int tests = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < tests; i++) {
            String s = f(scanner.nextLine());
            if (l1.contains(s)) System.out.println("ACC");
            else System.out.println("WA");
        }
    }
    
    public static void main(String[] args) {
        solve();
    }
}

public class codeforces_61_B {
    public static void permute(List<String> arr, List<List<String>> result) {
        permuteHelper(arr, 0, result);
    }
    
    private static void permuteHelper(List<String> arr, int index, List<List<String>> result) {
        if (index >= arr.size() - 1) {
            result.add(new ArrayList<String>(arr));
            return;
        }
        
        for (int i = index; i < arr.size(); i++) {
            Collections.swap(arr, i, index);
            permuteHelper(arr, index + 1, result);
            Collections.swap(arr, i, index);
        }
    }
}

// End of Code.
