import java.util.Scanner;

public class s592421258 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String doubledInput = input + input;
        String target = scanner.nextLine();
        System.out.println(doubledInput.contains(target) ? "Yes" : "No");
    }
}

// 
