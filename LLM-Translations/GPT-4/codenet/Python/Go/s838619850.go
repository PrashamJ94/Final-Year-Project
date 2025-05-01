package main

import (
	"fmt"
)

func main() {
	var S, T string
	fmt.Scan(&S)
	fmt.Scan(&T)

	N := len(S)
	M := len(T)
	ans := M

	for i := 0; i <= N-M; i++ {
		S_2 := S[i : i+M]
		cnt := 0
		for j := 0; j < M; j++ {
			if T[j] != S_2[j] {
				cnt++
			}
		}
		if cnt < ans {
			ans = cnt
		}
	}
	fmt.Println(ans)
}

// 
