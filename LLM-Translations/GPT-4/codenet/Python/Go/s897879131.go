package main

import "fmt"

func main() {
	var R, G, B, N int
	fmt.Scan(&R, &G, &B, &N)

	score := 0
	for i := 0; i <= N/R; i++ {
		for j := 0; j <= (N-i*R)/G; j++ {
			if N-i*R-j*G >= 0 && (N-i*R-j*G)%B == 0 {
				score++
			}
		}
	}

	fmt.Println(score)
}
// 
