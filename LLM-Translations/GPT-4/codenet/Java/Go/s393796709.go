package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD int64 = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	xx := toInts(strings.TrimSpace(line))
	min := min(xx[0], xx[1])
	max := max(xx[0], xx[1])
	var res int64
	if min == max {
		f := f(min)
		res = (2 * f * f) % MOD
	} else if min+1 == max {
		f := f(min)
		res = (f * ((f * int64(max)) % MOD)) % MOD
	} else {
		res = 0
	}
	fmt.Println(res)
}

func f(n int) int64 {
	var res int64 = 1
	for i := 2; i <= n; i++ {
		res = (res * int64(i)) % MOD
	}
	return res
}

func toInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func toInts(s string) []int {
	a := strings.Split(s, " ")
	o := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		o[i] = toInt(a[i])
	}
	return o
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
