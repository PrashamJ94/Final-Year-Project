
package main

import (
	"fmt"
	"math"
)

var d int

func read() bool {
	_, err := fmt.Scan(&d)
	return err == nil
}

func solve() int {
	var ans, n int
	ans = 0
	n = 600 / d
	for x := d; x < 600; x += d {
		ans += d * (x * x)
	}
	return ans
}

func main() {
	for read() {
		fmt.Println(solve())
	}
}

// 
