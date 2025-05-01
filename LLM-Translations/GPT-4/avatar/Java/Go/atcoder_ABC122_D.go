
package main

import (
	"fmt"
	"strings"
)

const MOD int64 = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}

func main() {
	var N int
	fmt.Scan(&N)

	memo := make([]map[string]int64, N+1)
	for i := range memo {
		memo[i] = make(map[string]int64)
	}

	fmt.Println(calc(N, "TTT", memo))
}

func calc(N int, last3 string, memo []map[string]int64) int64 {
	if val, ok := memo[N][last3]; ok {
		return val
	}

	if N == 0 {
		return 1
	}

	var result int64
	for _, c := range TOKENS {
		if isOK(last3 + c) {
			result = (result + calc(N-1, last3[1:]+c, memo)) % MOD
		}
	}

	memo[N][last3] = result
	return result
}

func isOK(last4 string) bool {
	if strings.Contains(last4, "AGC") {
		return false
	}

	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s := string(vals)
		if strings.Contains(s, "AGC") {
			return false
		}
	}

	return true
}

// //End of Code.
