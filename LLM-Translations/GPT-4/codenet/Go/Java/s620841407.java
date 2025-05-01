
import java.io.*;
import java.util.*;

public class s620841407 {
    static final int MOD = 1000000007;
    static final int ALPHABET_NUM = 26;
    static final long INF_INT64 = Long.MAX_VALUE;
    static final long INF_BIT60 = 1L << 60;
    static final int INF_INT32 = Integer.MAX_VALUE;
    static final int INF_BIT30 = 1 << 30;
    static final int NIL = -1;

    // General purpose
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            edges.add(new int[]{x, y});
        }

        ReRootingSolver s = new ReRootingSolver(n, edges, 1, (x, y) -> x * y % m, (v, p) -> v + 1);
        for (int i = 0; i < n; i++) {
            System.out.println(s.query(i) - 1);
        }
    }

    static class ReRootingSolver {
        int nodeCount;

        List<Integer>[] adjacents;
        List<Integer>[] indexForAdjacents;

        long[] res;
        long[][] dp;

        long identity;
        LongBinaryOperator operate;
        LongIntToLongFunction operateNode;

        public ReRootingSolver(int nodeCount, List<int[]> edges, long identity, LongBinaryOperator operate, LongIntToLongFunction operateNode) {
            this.nodeCount = nodeCount;
            this.identity = identity;
            this.operate = operate;
            this.operateNode = operateNode;

            adjacents = new List[nodeCount];
            indexForAdjacents = new List[nodeCount];
            for (int i = 0; i < nodeCount; i++) {
                adjacents[i] = new ArrayList<>();
                indexForAdjacents[i] = new ArrayList<>();
            }

            for (int[] e : edges) {
                indexForAdjacents[e[0]].add(adjacents[e[1]].size());
                indexForAdjacents[e[1]].add(adjacents[e[0]].size());
                adjacents[e[0]].add(e[1]);
                adjacents[e[1]].add(e[0]);
            }

            dp = new long[nodeCount][];
            res = new long[nodeCount];

            for (int i = 0; i < nodeCount; i++) {
                dp[i] = new long[adjacents[i].size()];
            }

            if (nodeCount > 1) {
                initialize();
            } else {
                res[0] = operateNode.applyAsLong(identity, 0);
            }
        }

        public long query(int node) {
            return res[node];
        }

        void initialize() {
            int[] parents = new int[nodeCount];
            int[] order = new int[nodeCount];

            int index = 0;
            Deque<Integer> stack = new ArrayDeque<>();
            stack.push(0);
            parents[0] = -1;
            while (!stack.isEmpty()) {
                int node = stack.pop();
                order[index++] = node;
                for (int i = 0; i < adjacents[node].size(); i++) {
                    int adjacent = adjacents[node].get(i);
                    if (adjacent == parents[node]) {
                        continue;
                    }
                    stack.push(adjacent);
                    parents[adjacent] = node;
                }
            }

            for (int i = order.length - 1; i >= 1; i--) {
                int node = order[i];
                int parent = parents[node];

                long accum = identity;
                int parentIndex = -1;
                for (int j = 0; j < adjacents[node].size(); j++) {
                    if (adjacents[node].get(j) == parent) {
                        parentIndex = j;
                        continue;
                    }
                    accum = operate.applyAsLong(accum, dp[node][j]);
                }
                dp[parent][indexForAdjacents[node].get(parentIndex)] = operateNode.applyAsLong(accum, node);
            }

            for (int i = 0; i < order.length; i++) {
                int node = order[i];
                long accum = identity;
                long[] accumsFromTail = new long[adjacents[node].size()];
                accumsFromTail[accumsFromTail.length - 1] = identity;
                for (int j = accumsFromTail.length - 1; j >= 1; j--) {
                    accumsFromTail[j - 1] = operate.applyAsLong(dp[node][j], accumsFromTail[j]);
                }
                for (int j = 0; j < accumsFromTail.length; j++) {
                    dp[adjacents[node].get(j)][indexForAdjacents[node].get(j)] = operateNode.applyAsLong(operate.applyAsLong(accum, accumsFromTail[j]), node);
                    accum = operate.applyAsLong(accum, dp[node][j]);
                }
                res[node] = operateNode.applyAsLong(accum, node);
            }
        }
    }

    @FunctionalInterface
    interface LongBinaryOperator {
        long applyAsLong(long left, long right);
    }

    @FunctionalInterface
    interface LongIntToLongFunction {
        long applyAsLong(long value, int index);
    }
}


