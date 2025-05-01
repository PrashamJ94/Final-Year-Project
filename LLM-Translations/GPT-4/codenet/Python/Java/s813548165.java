import java.util.Scanner;

public class s813548165 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    String[] input = scanner.next().split(" ");
    String S = input[0];
    String T = input[1];

    StringBuilder charLists = new StringBuilder();

    for (int i = 0; i < N; i++) {
      charLists.append(S.charAt(i));
      charLists.append(T.charAt(i));
    }

    System.out.println(charLists.toString());
  }
}
// 
