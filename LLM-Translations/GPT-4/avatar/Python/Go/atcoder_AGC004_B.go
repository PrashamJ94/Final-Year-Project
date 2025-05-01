
package main

import (
	"fmt"
)

func main() {
	var n, x int
	fmt.Scanf("%d %d", &n, &x)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		m := a[i]
		for j := 0; j < n; j++ {
			k := i - j
			if k < 0 {
				k += n
			}
			if a[k] < m {
				m = a[k]
			}
			b[j][i] = m
		}
	}

	m := int(1e15)
	for i, j := range b {
		sum := 0
		for _, v := range j {
			sum += v
		}
		if sum+x*i < m {
			m = sum + x*i
		}
	}
	fmt.Println(m)
}
// End of Code

