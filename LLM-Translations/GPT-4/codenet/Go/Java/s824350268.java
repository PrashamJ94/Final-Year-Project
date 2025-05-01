
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class s824350268 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());

        int sqrtN = (int) Math.sqrt(N);
        int min = N;

        for (int i = 1; i <= sqrtN; i++) {
            if (N % i != 0) {
                continue;
            }

            int num = i + (N / i) - 2;
            if (num < min) {
                min = num;
            }
        }

        System.out.println(min);
    }

    static class Graph {
        int n;
        List<Integer>[] edges;

        public Graph(int n) {
            this.n = n;
            this.edges = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                this.edges[i] = new ArrayList<>();
            }
        }

        public void addEdge(int u, int v) {
            this.edges[u].add(v);
            this.edges[v].add(u);
        }
    }

    static void dfs(int c, List<Integer>[] edges, Map<Integer, Boolean> visited) {
        visited.put(c, true);

        for (int v : edges[c]) {
            if (!visited.getOrDefault(v, false)) {
                dfs(v, edges, visited);
            }
        }
    }

    static int abs(int a) {
        return Math.abs(a);
    }

    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return calcMod(t * t);
        } else {
            return calcMod(n * powMod(n, p - 1));
        }
    }

    static int min(int... nums) {
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    static int max(int... nums) {
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    static void printIntArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            if (i > 0) {
                System.out.print(", ");
            }
            System.out.print(array[i]);
        }
        System.out.println("]");
    }

    static int calcMod(int x, int mod) {
        return x % mod;
    }

    static String reverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }

    static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }

        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
}


