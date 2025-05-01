package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second int
}

func Cut(array []Pair, index int) []Pair {
	if index < 1 {
		return []Pair{}
	}
	if index <= array[0].first {
		return []Pair{{index, array[0].second}}
	}
	for i := len(array) - 1; i > 0; i-- {
		if array[i-1].first < index {
			return append(array[:i], Pair{index, array[i].second})
		}
	}
	return array
}

func IsPossible(A []int, K int) bool {
	dp := []Pair{{A[0], 0}}
	for _, a := range A[1:] {
		if a <= dp[len(dp)-1].first {
			dp = Cut(dp, a)
		} else {
			dp = append(dp, Pair{a, 0})
		}
		isAdded := false
		for j := len(dp) - 1; j >= 0; j-- {
			if dp[j].second < K-1 {
				dp = append(Cut(dp, dp[j].first-1), Pair{dp[j].first, dp[j].second + 1})
				if dp[len(dp)-1].first < a {
					dp = append(dp, Pair{a, 0})
				}
				isAdded = true
				break
			}
		}
		if !isAdded {
			return false
		}
	}
	return true
}

func Bisect(A []int, x, y int) int {
	if y == x+1 {
		return y
	} else if IsPossible(A, (x+y)/2) {
		return Bisect(A, x, (x+y)/2)
	} else {
		return Bisect(A, (x+y)/2, y)
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	A := make([]int, n)
	for i := range A {
		fmt.Scanf("%d", &A[i])
	}
	sort.Ints(A)
	fmt.Println(Bisect(A, 0, n))
}

End of Code.
