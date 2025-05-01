
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func bisectLeft(a []int, x int, lo int, hi int) int {
	for lo < hi {
		mid := (lo + hi) / 2
		if a[mid] < x {
			lo = mid + 1
		} else {
			hi = mid
		}
	}
	return lo
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	N, _ := strconv.Atoi(parts[0])
	K, _ := strconv.Atoi(parts[1])

	scanner.Scan()
	Astr := strings.Split(scanner.Text(), " ")
	A := make([]int, N)
	for i, a := range Astr {
		A[i], _ = strconv.Atoi(a)
		A[i] = (A[i] % K) - 1
	}

	sumA := make([]int, N+1)
	count := 0
	modK := make(map[int][]int)
	modK[0] = []int{0}

	for i := 0; i < N; i++ {
		sumA[i+1] = (sumA[i] + A[i]) % K
		modK[sumA[i+1]] = append(modK[sumA[i+1]], i+1)
	}

	for _, v := range modK {
		lenK := len(v)
		for i, a := range v {
			count += bisectLeft(v, a+K, i, lenK) - i - 1
		}
	}

	fmt.Println(count)
}


