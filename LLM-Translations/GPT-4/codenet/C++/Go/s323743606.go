
package main

import (
	"fmt"
)

func main() {
	m := make(map[int]int)
	for i := 0; i*200 < 5001; i++ {
		for j := 0; j*300 < 5001; j++ {
			for k := 0; k*500 < 5001; k++ {
				w := i*200 + j*300 + k*500
				p := (i/5)*5*380*8/10+(i%5)*380 +
					(j/4)*4*550*85/100+(j%4)*550 +
					(k/3)*3*850*88/100+(k%3)*850
				if m[w] != 0 {
					m[w] = min(m[w], p)
				} else {
					m[w] = p
				}
			}
		}
	}

	var n int
	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		fmt.Println(m[n])
	}
}
// 


