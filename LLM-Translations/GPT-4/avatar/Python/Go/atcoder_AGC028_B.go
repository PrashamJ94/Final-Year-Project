package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD int64 = 1000000007
const Nsq int64 = 1000
const M int64 = 1000000
var fact [M]int64
var inv [Nsq]int64

func pow(a, b, m int64) int64 {
	result := int64(1)
	for b > 0 {
		if b & 1 == 1 {
			result = (result*a) % m
		}
		b >>= 1
		a = (a*a) % m
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	A := make([]int64, N)
	for i, v := range strings.Split(scanner.Text(), " ") {
		A[i], _ = strconv.ParseInt(v, 10, 64)
	}

	fact[0] = 1
	for n := int64(1); n < Nsq; n++ {
		fact[n] = (fact[n-1] * n) % MOD
	}

	for i := range inv {
		inv[i] = pow(int64(i+1), MOD-2, MOD)
	}
	for i := int64(1); i < N; i++ {
		inv[i] = (inv[i] + inv[i-1]) % MOD
	}

	ans := int64(0)
	for i := int64(0); i < N; i++ {
		ans = (ans + A[i]*(inv[i]+inv[N-1-i]-1)) % MOD
	}

	ans = (ans * fact[N]) % MOD
	fmt.Println(ans)
}
// End of Code


Please note some differences due to the language specific constraints:
1. Go doesn't support `numpy`. Hence, all the mathematical operations are done using standard Go operations.
2. In Go, array sizes must be constant. Thus, the size of `fact` and `inv` arrays is set to the maximum size needed (`M` and `Nsq` respectively).
3. Go doesn't have direct support for array broadcasting. Thus, the operations that were done using broadcasting in the original Python code are implemented using loops in Go.
4. The `pow` function is used to calculate the power with modulus. It uses the binary exponentiation method, which is a standard method for calculating power under modulus. It is equivalent to the Python `pow` function with three arguments.
