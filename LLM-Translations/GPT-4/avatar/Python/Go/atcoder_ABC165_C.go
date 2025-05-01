package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	res := 0
	var rec func(A []int)
	rec = func(A []int) {
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			if ans > res {
				res = ans
			}
			return
		}
		last_max := 1
		if len(A) != 0 {
			last_max = A[len(A)-1]
		}
		for i := last_max; i <= M; i++ {
			rec(append(A, i))
		}
	}
	rec([]int{})
	fmt.Println(res)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	N, _ := strconv.Atoi(next(scanner))
	M, _ := strconv.Atoi(next(scanner))
	Q, _ := strconv.Atoi(next(scanner))
	a, b, c, d := make([]int, Q), make([]int, Q), make([]int, Q), make([]int, Q)
	for i := 0; i < Q; i++ {
		a[i], _ = strconv.Atoi(next(scanner))
		b[i], _ = strconv.Atoi(next(scanner))
		c[i], _ = strconv.Atoi(next(scanner))
		d[i], _ = strconv.Atoi(next(scanner))
	}
	solve(N, M, Q, a, b, c, d)
}

func next(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// End of Code
