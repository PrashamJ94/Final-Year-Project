
package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	const MOD = 1000000007
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := range A {
		fmt.Scan(&A[i])
	}

	_lcm := 1
	for _, a := range A {
		_lcm = _lcm * a / gcd(_lcm, a)
	}

	var ans int64
	ans = int64(_lcm)
	for _, s := range A {
		ans = ans * int64(math.Pow(float64(s), float64(MOD-2))) % MOD
	}

	fmt.Println(ans % MOD)
}
// End of Code

