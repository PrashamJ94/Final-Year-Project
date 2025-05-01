package main

import (
	"fmt"
)

func main() {
	var a, b, n int
	var sum int
	var i, j int
	for {
		_, err := fmt.Scanf("%d %d %d", &a, &b, &n)
		if err != nil {
			break
		}
		a -= a / b * b
		sum = 0
		for i = 1; i <= n; i++ {
			a *= 10
			for j = 9; j >= 0; j-- {
				if b*j <= a {
					break
				}
			}
			a -= b * j
			sum += j
		}
		fmt.Printf("%d\n", sum)
	}
}

// 
