
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func p(a, b, n int) int {
	if a < b {
		return a + b*n
	} else {
		return b + a*n
	}
}

func f(from int, d []int, e1 []int, e2 []int, b []bool) int {
	if b[from] {
		return -1
	}
	if d[from] != 0 {
		return d[from]
	}
	b[from] = true
	defer func() { b[from] = false }()
	var max int
	to := e1[from]
	if to != 0 {
		now := f(to, d, e1, e2, b)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	to = e2[from]
	if to != 0 {
		now := f(to, d, e1, e2, b)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	d[from] = max + 1
	return d[from]
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n-1)
		for j := 0; j < n-1; j++ {
			a[i][j] = nextInt(sc) - 1
		}
	}
	e1 := make([]int, 1000000)
	e2 := make([]int, 1000000)
	d := make([]int, 1000000)
	b := make([]bool, 1000000)
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j], n)
			to := p(i, a[i][j+1], n)
			if e1[from] == 0 {
				e1[from] = to
			} else if e2[from] == 0 {
				e2[from] = to
			} else {
				fmt.Println("-1")
				return
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		from := p(i, a[i][0], n)
		now := f(from, d, e1, e2, b)
		if now < 0 {
			ans = -1
			break
		}
		if now > ans {
			ans = now
		}
	}
	fmt.Println(ans)
}


