package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const MOD int64 = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	l := make([]int, n)

	for i := 0; i < n; i++ {
		l[i] = nextInt(sc)
	}

	sort.Ints(l)

	fmt.Println(l[n/2] - l[n/2-1])
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

func gcd(m, n int64) int64 {
	if m < n {
		return gcd(n, m)
	}
	if n == 0 {
		return m
	}
	return gcd(n, m%n)
}

func lcm(m, n int64) int64 {
	return m * n / gcd(m, n)
}

type Pair struct {
	key   int
	value int
}

func (p *Pair) getValue() int {
	return p.value
}

func (p *Pair) getKey() int {
	return p.key
}

// 
