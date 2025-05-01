package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)

	var j, i, x1, y1, c int64 = 2, 0, 0, 0, 0
	ans := true
	c = max(x, y)

	if c > b {
		fmt.Println("0")
		ans = false
	}

	for c%min(x, y) != 0 && ans {
		if x > y {
			c = x * j
			j++
		} else {
			c = y * j
			j++
		}

		if c > b {
			fmt.Println("0")
			ans = false
			break
		}
	}

	if ans {
		var count int64 = 0
		i = a

		for i = a; i <= b; i++ {
			if i%c == 0 {
				break
			}
		}

		if i != b+1 {
			fmt.Println(((b - i) / c) + 1)
		} else {
			fmt.Println("0")
		}
	}
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

// //End of Code
