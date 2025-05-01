import java.util.*;

public class s085712108 {
    static int MOD = 7007;

    static class QUEUE {
        int a, b, c, tot;
    }

    static ArrayList<ArrayList<Integer>> Hash = new ArrayList<>();

    static boolean HASH(int n) {
        for (int i = 0; i < Hash.get(n % MOD).size(); i++)
            if (n == Hash.get(n % MOD).get(i))
                return false;
        Hash.get(n % MOD).add(n);
        return true;
    }

    public static void main(String[] args) {
        for (int i = 0; i < MOD; i++) {
            Hash.add(new ArrayList<>());
        }

        QUEUE Push = new QUEUE();
        Push.tot = 0;
        Queue<QUEUE> que = new LinkedList<>();

        Scanner sc = new Scanner(System.in);
        Push.a = sc.nextInt();
        Push.b = sc.nextInt();
        Push.c = sc.nextInt();
        sc.close();

        que.add(Push);

        int[][] F = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

        while (!que.isEmpty()) {
            QUEUE Fro = que.poll();

            if (Fro.a == Fro.b && Fro.b == Fro.c) {
                System.out.println(Fro.tot);
                return;
            }

            for (int i = 0; i < 6; i++) {
                Push = new QUEUE();
                Push.tot = Fro.tot + 1;
                Push.a = Fro.a + F[i][0];
                Push.b = Fro.b + F[i][1];
                Push.c = Fro.c + F[i][2];

                int n = Push.a * 10000 + Push.b * 100 + Push.c;
                if (!HASH(n)) continue;
                que.add(Push);
            }
        }
    }
}
// 
