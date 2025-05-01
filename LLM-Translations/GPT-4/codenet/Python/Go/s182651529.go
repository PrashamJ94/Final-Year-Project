
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	scoreStr := ""
	fmt.Scan(&scoreStr)
	scoreStrs := strings.Split(scoreStr, " ")
	score := make([]int, len(scoreStrs))
	for i, s := range scoreStrs {
		score[i], _ = strconv.Atoi(s)
	}

	mae := 0
	usiro := K
	for i := 0; i < N-K; i++ {
		if score[mae] < score[usiro] {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		mae++
		usiro++
	}
}
// 


