import java.util.Scanner;

public class s867013108 {

	public static void main(String[] args) {
		int n;
		int[] nyuyoku_ticket = new int[DAYS];
		int[] pool_ticket = new int[DAYS];
		int[] nyuyoku_member = new int[DAYS];
		int[] pool_member = new int[DAYS];
		int[] seiki_ryoukin = new int[DAYS];
		int[] waribiki_ryoukin = new int[DAYS];
		int[] saiyasune = new int[DAYS];
		final int DAYS = 365;

		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			nyuyoku_ticket[i] = sc.nextInt();
			pool_ticket[i] = sc.nextInt();
			nyuyoku_member[i] = sc.nextInt();
			pool_member[i] = sc.nextInt();

			if (nyuyoku_member[i] >= 5 && pool_member[i] >= 2) {
				seiki_ryoukin[i] = (((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8) / 10;
				saiyasune[i] = seiki_ryoukin[i];
			} else if (nyuyoku_member[i] >= 5) {
				seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
				waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * 2)) * 8) / 10;
				saiyasune[i] = Math.min(seiki_ryoukin[i], waribiki_ryoukin[i]);
			} else if (pool_member[i] >= 2) {
				seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
				waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8) / 10;
				saiyasune[i] = Math.min(seiki_ryoukin[i], waribiki_ryoukin[i]);
			} else {
				seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
				waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8) / 10;
				saiyasune[i] = Math.min(seiki_ryoukin[i], waribiki_ryoukin[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			System.out.println(saiyasune[i]);
		}
		sc.close();
	}
}
// 
