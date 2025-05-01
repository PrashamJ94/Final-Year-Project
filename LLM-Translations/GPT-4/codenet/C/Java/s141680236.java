
import java.util.Scanner;
import java.util.Stack;

public class s141680236 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        while (scanner.hasNext()) {
            String input = scanner.next();

            if (input.equals("+")) {
                int yamagami = stack.pop();
                int chonda = stack.pop();
                stack.push(chonda + yamagami);
            } else if (input.equals("-")) {
                int yamagami = stack.pop();
                int chonda = stack.pop();
                stack.push(chonda - yamagami);
            } else if (input.equals("*")) {
                int yamagami = stack.pop();
                int chonda = stack.pop();
                stack.push(chonda * yamagami);
            } else {
                stack.push(Integer.parseInt(input));
            }
        }

        System.out.println(stack.pop());
    }
}

// 
