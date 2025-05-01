package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, 200000)
	tmpa := make([]int, 200000)
	light := make([]int, 200010)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < n; i++ {
		r := i - a[i]
		l := i + a[i]
		light[r]++
		light[l+1]--
	}

	for i := 0; i < k; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			tmpa[j] = a[j]
			sum += light[j]
			a[j] = sum
		}
		for j := 0; j < n; j++ {
			r := j - tmpa[j]
			l := j + tmpa[j]
			light[r]--
			light[l+1]++
			r = j - a[j]
			l = j + a[j]
			light[r]++
			light[l+1]--
		}
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j] != a[j+1] {
				isSame = false
				break
			}
		}
		if isSame && a[0] == n {
			break
		}
	}

	for j := 0; j < n; j++ {
		fmt.Print(a[j])
		if j == n-1 {
			fmt.Println()
		} else {
			fmt.Print(" ")
		}
	}
}
// 
