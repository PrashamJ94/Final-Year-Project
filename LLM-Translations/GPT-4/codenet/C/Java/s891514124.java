public class s891514124 {

  public static void main(String[] args) {

    java.util.Scanner scanner = new java.util.Scanner(System.in);
    int S = scanner.nextInt();
    scanner.close();

    if (S < 60) {
      System.out.printf("0:0:%d%n", S);
    } else if (S < 3600) {
      System.out.printf("0:%d:%d%n", (int) S / 60, S % 60);
    } else {
      System.out.printf("%d:%d:%d%n", (int) S / 3600, (int) (S % 3600) / 60, (S % 60) % 60);
    }
  }
}

// 
