package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	sort.Ints(a)
	if a[n-1] == 0 {
		fmt.Println(0)
		return
	}

	ans := 0
	for {
		if len(a) == 1 {
			ans = a[0]
			break
		}
		a = funcA(a)
	}

	fmt.Println(ans)
}

func funcA(A []int) []int {
	a := A
	min := 0
	for i := 0; i < len(a); i++ {
		if a[i] == 0 {
			a = append(a[:i], a[i+1:]...)
			i--
		} else {
			if min != 0 {
				a[i] = a[i] % min
				if a[i] == 1 {
					fmt.Println(1)
					return
				}
			} else {
				min = a[i]
			}
		}
	}
	sort.Ints(a)
	return a
}

// //End of Code.
