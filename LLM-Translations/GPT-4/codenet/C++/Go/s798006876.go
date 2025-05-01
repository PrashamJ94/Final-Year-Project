
package main

import (
	"fmt"
)

const MAX_N = 1e3

var data [MAX_N]int

func main() {
	var m, nmi, nma int
	for {
		fmt.Scan(&m, &nmi, &nma)
		if nmi == 0 {
			break
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&data[i])
		}
		ma := 0
		ans := 0
		for i := nmi - 1; i < nma; i++ {
			if ma <= data[i]-data[i+1] {
				ans = i + 1
				ma = data[i] - data[i+1]
			}
		}
		fmt.Println(ans)
	}
}
// 


