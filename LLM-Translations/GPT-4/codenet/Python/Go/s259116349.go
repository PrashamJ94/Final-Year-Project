
package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}
	divs := make([][]int, 100)

	for i := 1; i <= 100; i++ {
		tmp := make([]int, len(primes))
		for j, p := range primes {
			tmp[j] = 0
			for i%p == 0 {
				i = i / p
				tmp[j] += 1
			}
		}
		divs[i-1] = tmp
	}

	divsum := make([]int, len(primes))
	for i := 1; i <= N; i++ {
		for j := range primes {
			divsum[j] += divs[i-1][j]
		}
	}

	num := func(n int) int {
		count := 0
		for _, x := range divsum {
			if x >= n-1 {
				count++
			}
		}
		return count
	}

	ans := 0

	// >=74
	ans += num(75)

	// >=14 & 13~4
	ans += num(15) * (num(5) - 1)

	// >=24 & 23~2
	ans += num(25) * (num(3) - 1)

	// >=4,>=4 & >=2
	ans += num(5) * (num(5) - 1) * (num(3) - 2) / 2
	fmt.Println(ans)
}

// 
