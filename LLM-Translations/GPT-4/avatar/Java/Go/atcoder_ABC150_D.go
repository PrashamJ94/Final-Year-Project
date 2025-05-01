package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] /= 2
	}
	var gcd int
	lcd := 1
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, a[i])
		lcd = lcd * a[i] / gcd
		if lcd > m {
			fmt.Println(0)
			return
		}
	}
	for i := 0; i < n; i++ {
		if (lcd / a[i])%2 == 0 {
			fmt.Println(0)
			return
		}
	}
	fmt.Println((m/lcd + 1) / 2)
}

func getGCD(a, b int) int {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b)
	}
}

// //End of Code.
