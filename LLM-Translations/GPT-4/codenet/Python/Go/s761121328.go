package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	s := A[0] ^ A[1]
	for i := 2; i < N; i++ {
		s = s ^ A[i]
	}

	B := make([]int, N)
	for i := 0; i < N; i++ {
		B[i] = s ^ A[i]
	}

	L := make([]string, N)
	for i, a := range B {
		L[i] = strconv.Itoa(a)
	}
	Lstr := strings.Join(L, " ")
	fmt.Println(Lstr)
}
// 
