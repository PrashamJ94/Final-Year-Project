
import java.util.*;

public class s646324174 {
    static int top;
    static int[] S = new int[10000];

    public static void push(int x) {
        S[++top] = x;
    }

    public static int pop() {
        return S[top--];
    }

    public static void main(String[] args) {
        int a, b;
        String s;
        top = 0;
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            s = sc.next();
            if (s.charAt(0) == '+') {
                b = pop();
                a = pop();
                push(a + b);
            } else if (s.charAt(0) == '-') {
                b = pop();
                a = pop();
                push(a - b);
            } else if (s.charAt(0) == '*') {
                b = pop();
                a = pop();
                push(a * b);
            } else {
                push(Integer.parseInt(s));
            }
        }
        System.out.println(pop());
    }
}
// 


