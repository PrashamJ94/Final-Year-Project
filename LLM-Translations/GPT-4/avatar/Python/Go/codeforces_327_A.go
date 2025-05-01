package main

import (
	"fmt"
	"strings"
)

func find(s string, ch string) []int {
	var indices []int
	for i, ltr := range s {
		if string(ltr) == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	s = strings.Replace(s, "", "", -1)
	if !strings.Contains(s, "0") {
		fmt.Println(n - 1)
	} else {
		indices := find(s, "0")
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			maximum := 0
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					maximum = max(maximum, 2+2*(abs(i-j))-1)-(abs(indices[i]-indices[j])-1))
				}
			}
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// End of Code

