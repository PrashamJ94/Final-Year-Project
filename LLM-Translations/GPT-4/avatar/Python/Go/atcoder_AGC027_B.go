package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	X, _ := strconv.Atoi(sc.Text())

	A := make([]int, N)
	S := make([]int, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		A[i], _ = strconv.Atoi(sc.Text())
		if i == 0 {
			S[i] = A[i]
		} else {
			S[i] = S[i-1] + A[i]
		}
	}

	ans := 1<<31 - 1
	for k := 0; k < N; k++ {
		E := (k + 1) * X
		for j := N - 1 - 2*k; j >= 0; j -= k + 1 {
			E += 2 * S[j]
		}
		if E < ans {
			ans = E
		}
	}

	fmt.Println(ans + N*X + 5*S[N-1])
}

// End of Code

