
import java.util.Scanner;
import java.util.ArrayList;

class TSize {
    int r;
    int c;

    TSize() {
        r = 0;
        c = 0;
    }

    TSize(int Ar, int Ac) {
        r = Ar;
        c = Ac;
    }
}

class TMcmSolver {
    private int[][] FMemo;
    private ArrayList<TSize> fChain;

    private static int Count(TSize Left, TSize Right) {
        return Left.r * Right.c * Left.c;
    }

    private int Solve(int s, int l) {
        assert (s <= l);
        if (s == l)
            return 0;
        if (FMemo[s][l] != 0)
            return FMemo[s][l];
        if (s + 1 == l) {
            FMemo[s][l] = Count(fChain.get(s), fChain.get(l));
        } else {
            int min = Integer.MAX_VALUE;
            for (int i = s; i < l; ++i) {
                int c = Solve(s, i) + Count(new TSize(fChain.get(s).r, fChain.get(i).c),
                        new TSize(fChain.get(i + 1).r, fChain.get(l).c)) + Solve(i + 1, l);
                min = Math.min(min, c);
            }
            FMemo[s][l] = min;
        }
        return FMemo[s][l];
    }

    TMcmSolver(ArrayList<TSize> Chain) {
        fChain = Chain;
        FMemo = new int[Chain.size()][Chain.size()];
        for (int i = 0; i < FMemo.length; ++i) {
            for (int j = 0; j < FMemo[0].length; ++j) {
                FMemo[i][j] = 0;
            }
        }
    }

    int Answer() {
        return Solve(0, FMemo.length - 1);
    }
}

public class s792884768 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if (n == 1) {
            System.out.println(0);
            return;
        }

        ArrayList<TSize> Chain = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            Chain.add(new TSize(scanner.nextInt(), scanner.nextInt()));
        }

        TMcmSolver Solver = new TMcmSolver(Chain);
        System.out.println(Solver.Answer());
    }
}

// 
