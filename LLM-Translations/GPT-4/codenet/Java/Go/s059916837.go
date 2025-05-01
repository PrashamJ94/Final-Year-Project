package main

import (
	"fmt"
	"math"
	"os"
	"strings"
)

func main() {
	var S, T string
	fmt.Scan(&S, &T)

	min := math.MaxInt32
	for i := 0; i <= len(S)-len(T); i++ {
		min = int(math.Min(float64(min), float64(find(S[i:i+len(T)], T))))
	}

	if min != math.MaxInt32 {
		fmt.Println(min)
	} else {
		fmt.Println(len(T))
	}
}

func find(a, b string) int {
	calc := 0
	for x := 0; x < len(a); x++ {
		if a[x] != b[x] {
			calc++
		}
	}
	return calc
}

// 
