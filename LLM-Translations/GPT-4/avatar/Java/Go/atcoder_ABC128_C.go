package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N, M int
	fmt.Scanf("%d %d", &N, &M)

	a := make([]int, N)

	for i := 0; i < M; i++ {
		var k int
		fmt.Scanf("%d", &k)

		for j := 0; j < k; j++ {
			var s int
			fmt.Scanf("%d", &s)
			s--
			a[s] = a[s] | (1 << i)
		}
	}

	var p int
	for i := 0; i < M; i++ {
		var x int
		fmt.Scanf("%d", &x)
		p |= (x << i)
	}

	ans := 0
	for s := 0; s < (1 << N); s++ {
		t := 0
		for i := 0; i < N; i++ {
			if ((s >> i) & 1) == 1 {
				t ^= a[i]
			}
		}
		if p == t {
			ans++
		}
	}

	fmt.Println(strconv.Itoa(ans))
}

// //End of Code.
