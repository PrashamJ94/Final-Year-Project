
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	a := make([][]rune, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i] = []rune(scanner.Text())
	}

	P, Q := int64(37), int64(47)
	powP, powQ := make([]int64, n+1), make([]int64, n+1)
	powP[0], powQ[0] = 1, 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * P
		powQ[i] = powQ[i-1] * Q
	}

	hashRow, hashCol := make([][]int64, n), make([][]int64, n)
	for i := 0; i < n; i++ {
		hashRow[i], hashCol[i] = make([]int64, n), make([]int64, n)
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				hashRow[i][k] += int64(a[i][j]) * powP[(j-k+n)%n]
				hashCol[j][k] += int64(a[i][j]) * powP[(i-k+n)%n]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				ok = ok && hashRow[(i+A)%n][B] == hashCol[(i+B)%n][A]
			}
			if ok {
				ans++
			}
		}
	}
	fmt.Println(ans)
}

// 
