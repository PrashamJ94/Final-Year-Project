import java.util.*;

public class s828550015 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        scanner.nextLine();

        ArrayList<Integer> p = getTopX(scanner, x);
        ArrayList<Integer> q = getTopX(scanner, y);
        ArrayList<Integer> r = getTopX(scanner, c);

        ArrayList<Integer> pq = new ArrayList<>(p);
        pq.addAll(q);
        Collections.sort(pq);

        Collections.sort(r, Collections.reverseOrder());

        for (int i = 0; i < Math.min(x + y, a + b, c); i++) {
            if (pq.get(i) < r.get(i)) {
                pq.set(i, r.get(i));
            }
        }

        long sum = 0;
        for (int num : pq) {
            sum += num;
        }

        System.out.println(sum);
    }

    private static ArrayList<Integer> getTopX(Scanner scanner, int x) {
        ArrayList<Integer> list = new ArrayList<>();
        for (String s : scanner.nextLine().split(" ")) {
            list.add(Integer.parseInt(s));
        }

        Collections.sort(list, Collections.reverseOrder());
        ArrayList<Integer> topX = new ArrayList<>(list.subList(0, x));
        return topX;
    }
}
// 
