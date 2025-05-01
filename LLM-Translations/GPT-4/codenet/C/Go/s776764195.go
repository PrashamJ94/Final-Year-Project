
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MAX_N   = 2000001
	MAX_Ai  = 10001
	STR_SIZE = 10000010
)

func getNum(p *[]byte) (int, *[]byte) {
	n := 0
	for {
		if len(*p) == 0 || **p < '0' || **p > '9' {
			break
		}
		n = n*10 + int(**p - '0')
		*p = (*p)[1:]
	}
	*p = (*p)[1:]
	return n, p
}

func CountingSort(A, B []int, k, len int) {
	var C [MAX_Ai]int
	for j := 1; j <= len; j++ {
		C[A[j]]++
	}
	for i := 1; i <= k; i++ {
		C[i] += C[i-1]
	}
	for j := len; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}
}

func main() {
	var i int
	var n int

	reader := bufio.NewReader(os.Stdin)
	p, _ := reader.Peek(STR_SIZE)
	n, &p = getNum(&p)

	A := make([]int, MAX_N)
	B := make([]int, MAX_N)

	for i = 1; i <= n; i++ {
		A[i], &p = getNum(&p)
	}

	CountingSort(A, B, MAX_Ai, n)

	for i = 1; i < n; i++ {
		fmt.Print(B[i], " ")
	}
	fmt.Println(B[i])
}

// 
