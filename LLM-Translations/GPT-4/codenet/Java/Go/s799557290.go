package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	ju := make([]bool, 100001)
	pe := make([]int, 100001)
	wa := 0
	ac := 0

	for i := 0; i < b; i++ {
		var n int
		var res string
		fmt.Scan(&n, &res)

		if res == "WA" && !ju[n-1] {
			pe[n-1]++
		}

		if res == "AC" {
			ju[n-1] = true
		}
	}

	for i := 0; i < a; i++ {
		if ju[i] {
			ac++
			wa += pe[i]
		}
	}

	fmt.Println(strconv.Itoa(ac) + " " + strconv.Itoa(wa))
}

// 
