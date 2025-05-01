
package main

import (
	"fmt"
	"math"
)

const (
	LIM = 20
	N   = 2e5 + 7
)

var (
	mn  [LIM][N]int
	pw  [N]int
)

type Ban struct {
	l   int
	r   int
	val int
}

func initSP(a []int) {
	n := len(a)
	for i := 0; i < n; i++ {
		mn[0][i] = a[i]
	}
	for i := 0; i+1 < LIM; i++ {
		for j := 0; j+(1<<(i+1)) <= n; j++ {
			mn[i+1][j] = int(math.Max(float64(mn[i][j]), float64(mn[i][j+(1<<i)])))
		}
	}
	pw[1] = 0
	for i := 2; i < N; i++ {
		pw[i] = pw[i/2] + 1
	}
}

func getSP(l, r int) int {
	r++
	p := pw[r-l]
	return int(math.Min(float64(mn[p][l]), float64(mn[p][r-(1<<p)])))
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		if a[i] > i {
			fmt.Println(-1)
			return
		}
		dl[i] = i - a[i]
	}
	ans := 0
	bans := []Ban{}
	for i := 0; i < n; i++ {
		r := i
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		ans += a[r]
		i = r
		bans = append(bans, Ban{r - a[r], r, r - a[r]})
	}
	initSP(dl)
	for _, t := range bans {
		if getSP(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}


