
package main

import (
	"fmt"
	"strings"
	"strconv"
)

func help(a int, b int, l []int) bool {
	var tot [][]int
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:i*a+a])
	}
	for _, i := range tot {
		sum := 0
		for _, j := range i {
			sum += j
		}
		if sum == b {
			return true
		}
	}
	return false
}

func solve() {
	var tot [][]int
	var x string
	fmt.Scan(&x)
	var s []int
	for _, i := range x {
		if string(i) == "O" {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}
	fmt.Print(strconv.Itoa(len(tot)), " ")
	for _, pair := range tot {
		fmt.Print(strconv.Itoa(pair[0]), "x", strconv.Itoa(pair[1]), " ")
	}
	fmt.Println()
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		solve()
	}
}
// End of Code

