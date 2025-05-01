
package main

import (
	"fmt"
)

func main() {
	var N, K int64
	var A [200100]int64
	var B [200100]int64

	for i := range B {
		B[i] = -1
	}

	var now int64 = 1
	var cnt int64 = 0

	fmt.Scan(&N, &K)

	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i])
	}

	var j int64
	B[1] = 0
	for j = 1; j <= K; j++ {
		now = A[now]

		if B[now] == -1 {
			B[now] = j
		} else {
			cnt = j
			break
		}
	}

	if j < K {
		var tmp int64
		tmp = (K - B[now]) % (cnt - B[now])

		for j := int64(0); j < tmp; j++ {
			now = A[now]
		}
	}

	fmt.Println(now)
}


