package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	c := make([]int, n-1)
	s := make([]int, n-1)
	f := make([]int, n-1)

	for i := 0; i < n-1; i++ {
		fmt.Scan(&c[i], &s[i], &f[i])
	}

	for i := 0; i < n-1; i++ {
		time := s[i] + c[i]
		for j := i + 1; j < n-1; j++ {
			if time%f[j] != 0 {
				time += f[j] - (time % f[j])
			}

			if time < s[j] {
				time = s[j]
			}

			time += c[j]
		}

		fmt.Println(time)
	}
	fmt.Println(0)
}

// 
