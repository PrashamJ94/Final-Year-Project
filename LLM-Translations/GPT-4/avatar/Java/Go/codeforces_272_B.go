package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	a := make([]int, 33)
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		a[rec(x)]++
	}

	var answer float64 = 0
	for i := 0; i < len(a); i++ {
		summ := (1 + a[i] - 1) / 2.0 * (a[i] - 1)
		answer += summ
	}

	fmt.Println(int64(answer))
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if (x & (1 << k)) != 0 {
			answer++
		}
	}
	return answer
}

// //End of Code.
