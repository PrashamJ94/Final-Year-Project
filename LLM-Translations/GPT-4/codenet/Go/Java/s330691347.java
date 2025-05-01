
import java.util.*;

public class s330691347 {

    static class Data implements Comparable<Data> {
        String X;

        Data(String X) {
            this.X = X;
        }

        @Override
        public int compareTo(Data o) {
            return this.X.compareTo(o.X);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();
        sc.nextLine();

        List<Data> s = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            s.add(new Data(sc.next()));
        }

        Collections.sort(s);

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < N; i++) {
            ans.append(s.get(i).X);
        }
        System.out.println(ans.toString());

        sc.close();
    }
}

// 
