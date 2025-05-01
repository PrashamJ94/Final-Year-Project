package main

import (
	"fmt"
)

var (
	memo [110][5][5][5]int
	mod  = 1000000007
)

func ok(last3 int, c int) bool {
	agc := 0
	for i := 0; i < 4; i++ {
		t := make([]int, 4)
		copy(t, last3)
		t[i], t[i-1] = t[i-1], t[i]
		if t[1] == 1 && t[2] == 3 && t[0] == 2 {
			agc += 1
		}
	}
	if agc >= 1 {
		return false
	}
	return true
}

func dfs(cur int, last3 int) int {
	if cur == n {
		return 1
	}
	if memo[cur][last3[0]][last3[1]][last3[2]] != -1 {
		return memo[cur][last3[0]][last3[1]][last3[2]]
	}
	ret := 0
	for c := 0; c < 4; c++ {
		if ok(last3, c) {
			ret = (ret + dfs(cur+1, append([]int{c}, last3[:2]...))) % mod
		}
	}
	memo[cur][last3[0]][last3[1]][last3[2]] = ret
	return ret
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < 110; i++ {
		for j := 0; j < 5; j++ {
			for k := 0; k < 5; k++ {
				for l := 0; l < 5; l++ {
					memo[i][j][k][l] = -1
				}
			}
		}
	}
	fmt.Println(dfs(0, []int{3, 3, 3}))
}

// End of Code

Please note this is a rough translation and might need adjustments based on the rest of your Go code.
