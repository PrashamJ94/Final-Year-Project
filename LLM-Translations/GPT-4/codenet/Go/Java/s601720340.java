
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class s601720340 {
	static int magic = 1000000007;
	static int N;
	static int[] p = new int[200000];

	public static void main(String[] args) {
		InputReader in = new InputReader();
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		// PARSE HELPER SESSION
		int X = in.nextInt();
		N = in.nextInt();
		for (int i = 0; i < N; i++) {
			p[i] = in.nextInt();
		}
		for (int i = 0; i <= 100; i++) {
			if (find(X - i) == 1) {
				out.printf("%d\n", X - i);
				out.flush();
				return;
			}
			if (find(X + i) == 1) {
				out.printf("%d\n", X + i);
				out.flush();
				return;
			}
		}
	}

	static int find(int n) {
		for (int i = 0; i < N; i++) {
			if (n == p[i]) {
				return 0;
			}
		}
		return 1;
	}

	static class InputReader {
		BufferedReader br;
		StringTokenizer st;

		public InputReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
			st = null;
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}


