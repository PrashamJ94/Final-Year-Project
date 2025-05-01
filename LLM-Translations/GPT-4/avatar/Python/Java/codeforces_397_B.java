public class codeforces_397_B {
    private int t;
    private int[][] queries;
    private String result;

    public CodeforcesTask397BSolution() {
        this.result = "";
        this.t = 0;
        this.queries = new int[0][];
    }

    public void readInput() {
        Scanner scanner = new Scanner(System.in);
        this.t = scanner.nextInt();
        this.queries = new int[this.t][];
        for (int i = 0; i < this.t; i++) {
            this.queries[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
        }
    }

    public void processTask() {
        List<String> res = new ArrayList<>();
        for (int[] query : this.queries) {
            int k = query[0] / query[1];
            res.add((k * query[2] >= query[0]) ? "Yes" : "No");
        }
        this.result = String.join("\n", res);
    }

    public String getResult() {
        return this.result;
    }

    public static void main(String[] args) {
        CodeforcesTask397BSolution solution = new CodeforcesTask397BSolution();
        solution.readInput();
        solution.processTask();
        System.out.println(solution.getResult());
    }
}
// End of Code
