
package main

import (
	"fmt"
	"math"
)

type int64 int64

func MAX(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func MIN(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func ABS(a int64) int64 {
	if a > 0 {
		return a
	} else {
		return -a
	}
}

func digit(n int64) int {
	res := 0
	for n > 0 {
		res++
		n /= 10
	}
	return res
}

func run() {
	var n int64
	fmt.Scan(&n)
	min := digit(n)
	for i := int64(1); i*i <= n; i++ {
		if n%i != 0 {
			continue
		}
		a := i
		b := n / i
		min = int(MIN(int64(min), MAX(int64(digit(a)), int64(digit(b)))))
	}
	fmt.Println(min)
}

func main() {
	run()
}


