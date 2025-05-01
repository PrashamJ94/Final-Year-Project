package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Pair struct {
	l, r int
}

func (p Pair) String() string {
	return fmt.Sprintf("%d %d", p.l, p.r)
}

var memo [][][]int
var a [][]int
var n int

func dp(fliped, idx, msk int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[fliped][idx][msk] != -1 {
		return memo[fliped][idx][msk]
	}
	x := bits.OnesCount(msk)
	ff := 0
	ans := int(1e9)
	for i := 0; i < n; i++ {
		if (msk & (1 << i)) == 0 {
			nf := x % 2
			if idx == n || a[fliped][idx] <= a[(nf+(ff%2))%2][i] {
				ans = min(ans, ff+dp((nf+(ff%2))%2, i, msk|1<<i))
			}
			ff++
		} else {
			x--
		}
	}
	memo[fliped][idx][msk] = ans
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	a = make([][]int, 2)
	for i := 0; i < 2; i++ {
		a[i] = make([]int, n)
		scanner.Scan()
		line := scanner.Text()
		fields := strings.Fields(line)
		for j, field := range fields {
			a[i][j], _ = strconv.Atoi(field)
		}
	}
	memo = make([][][]int, 2)
	for i := range memo {
		memo[i] = make([][]int, n+1)
		for j := range memo[i] {
			memo[i][j] = make([]int, 1<<n)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}
	ans := dp(0, n, 0)
	if ans >= int(1e8) {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// 
