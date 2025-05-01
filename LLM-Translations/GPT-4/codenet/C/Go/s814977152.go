package main

import (
	"fmt"
	"sort"
)

func miyukiti(asumisu, mizuhasu int) int {
	isihasu, matukisu := asumisu, mizuhasu
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	}
	return 0
}

func sumipe(hayaminn int, tomatu []int, yukinnko int) int {
	satorina, zaasan := 0, yukinnko-1
	for satorina <= zaasan {
		yukati := satorina + (zaasan-satorina)/2
		if tomatu[yukati] == hayaminn {
			return yukati
		} else if tomatu[yukati] < hayaminn {
			satorina = yukati + 1
		} else {
			zaasan = yukati - 1
		}
	}
	return 114513
}

func main() {
	var N int
	_, _ = fmt.Scan(&N)

	A := make([]int, 114514)
	tomatu := make([]int, 114514)
	mikakosi := make([]int, 114514)

	for inorinn := 0; inorinn < N; inorinn++ {
		_, _ = fmt.Scan(&A[inorinn])
		tomatu[inorinn] = A[inorinn]
	}

	sort.Slice(tomatu[:N], func(i, j int) bool {
		return miyukiti(tomatu[i], tomatu[j]) < 0
	})

	yukinnko := 1
	for inorinn := 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko++
		}
	}

	emirinn := 0
	for inorinn := 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn], tomatu, yukinnko)
		mikakosi[kugyu] = 1 - mikakosi[kugyu]
	}

	for inorinn := 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] == 1 {
			emirinn++
		}
	}

	fmt.Println(emirinn)
}

// 
