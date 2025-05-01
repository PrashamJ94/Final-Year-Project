package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	sc = bufio.NewScanner(os.Stdin)
)

func init() {
	sc.Split(bufio.ScanWords)
}

func getInt() int {
	sc.Scan()
	v, _ := strconv.Atoi(sc.Text())
	return v
}

func solve() {
	n := getInt()
	dp := make([]int, 1)
	dp[0] = -(1 << 60)
	for i := 0; i < n; i++ {
		num := getInt()
		num = -num
		if num >= dp[len(dp)-1] {
			dp = append(dp, num)
		} else {
			idx := sort.Search(len(dp), func(i int) bool { return dp[i] > num })
			dp[idx] = num
		}
	}

	fmt.Println(len(dp) - 1)
}

func main() {
	tc := getInt()
	for i := 0; i < tc; i++ {
		solve()
	}
}

// 
