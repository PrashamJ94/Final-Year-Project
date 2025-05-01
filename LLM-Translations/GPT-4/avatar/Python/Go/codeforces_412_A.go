package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	
	var v string
	fmt.Scan(&v)

	d := []string{"LEFT", "RIGHT"}
	f := k-1 < n-k
	m := min(k-1, n-k)
	
	var a []string
	for i := 0; i < m; i++ {
		a = append(a, d[1-f])
	}
	
	vArray := strings.Split(v, "")
	if !f {
		for i := len(vArray) - 1; i >= 0; i-- {
			a = append(a, "PRINT "+vArray[i])
			a = append(a, d[f])
		}
	} else {
		for _, i := range vArray {
			a = append(a, "PRINT "+i)
			a = append(a, d[f])
		}
	}
	
	for i := 0; i < len(a)-1; i++ {
		fmt.Println(a[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// End of Code
