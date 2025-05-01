
package main

import (
	"fmt"
)

const (
	DAYS = 365 // 最大何日か？
)

func main() {
	var n int
	var nyuyoku_ticket [DAYS]int
	var pool_ticket [DAYS]int
	var nyuyoku_member [DAYS]int
	var pool_member [DAYS]int
	var seiki_ryoukin [DAYS]int
	var waribiki_ryoukin [DAYS]int
	var saiyasune [DAYS]int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nyuyoku_ticket[i], &pool_ticket[i], &nyuyoku_member[i], &pool_member[i])
		if nyuyoku_member[i] >= 5 && pool_member[i] >= 2 {
			seiki_ryoukin[i] = (((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8) / 10
			saiyasune[i] = seiki_ryoukin[i]
		} else if nyuyoku_member[i] >= 5 {
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])
			waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * 2)) * 8) / 10
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		} else if pool_member[i] >= 2 {
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])
			waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8) / 10
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		} else {
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])
			waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8) / 10
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		}
	}
	for i := 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}


