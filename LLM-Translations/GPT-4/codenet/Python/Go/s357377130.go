package main

import "fmt"

func main() {
	var A, B, K int
	fmt.Scan(&A, &B, &K)

	if A+K-1 >= B-K+1 {
		for A <= B {
			fmt.Println(A)
			A++
		}
	} else {
		i := 0
		for i <= K-1 {
			fmt.Println(A + i)
			i++
		}
		for B-K+1 <= B {
			fmt.Println(B - K + 1)
			K--
		}
	}
}

// 
