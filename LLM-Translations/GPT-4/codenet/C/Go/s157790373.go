
package main

import (
	"fmt"
)

const LEN = 300

var n int
var A [LEN]int
var flag bool

func main() {
	var q, M int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&M)
		flag = false

		solve(-1, M)
		if flag == true {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

func solve(i int, m int) {
	if i > n {
		return
	} else if m < 0 {
		return
	} else if m == 0 || m-A[i+1] == 0 {
		flag = true
		return
	} else {
		// not use A[i]
		solve(i+1, m)
		// use A[i]
		solve(i+1, m-A[i])
	}
}


