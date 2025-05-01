package main

import (
	"fmt"
	"strings"
	"strconv"
)

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	var S, T string
	fmt.Scan(&S, &T)

	listS := strings.Split(S, "")
	listT := strings.Split(T, "")

	var NumberiMN []float64
	for i := 0; i < N; i++ {
		NumberiMN = append(NumberiMN, float64(i*M)/float64(N))
	}
	var Kaburij []int
	for j := 0; j < M; j++ {
		if float64(j) == NumberiMN[j] {
			Kaburij = append(Kaburij, j)
		}
	}
	var Kaburii []int
	for _, j := range Kaburij {
		Kaburii = append(Kaburii, int(float64(j*N)/float64(M)))
	}
	counter := 0
	Flag := 0
	KaburiSize := len(Kaburii)
	for counter <= KaburiSize-1 {
		if listS[Kaburii[counter]] == listT[Kaburij[counter]] {
			// do nothing
		} else {
			Flag = 1
			break
		}
		counter++
	}

	if Flag == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(strconv.Itoa(N * M / gcd(N, M)))
	}
}


// End of Code

