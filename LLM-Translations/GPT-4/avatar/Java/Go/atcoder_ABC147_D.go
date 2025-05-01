package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	var div int64 = int64(math.Pow(10, 9)) + 7
	var ans int64
	fmt.Scan(&n)

	A := make([]int64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	for i := 0; i < 60; i++ {
		var a, count1 int64
		for j := 0; j < n; j++ {
			if (A[j]>>i)&1 == 1 {
				count1++
			}
		}
		a = a + count1*(int64(n)-count1)
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}
		ans += a
		ans %= div
	}

	fmt.Println(ans)
}

// //End of Code
