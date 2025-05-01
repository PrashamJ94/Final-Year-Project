package main

import (
	"fmt"
	"sort"
)

type pair struct {
	t, d int
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	info := make([]pair, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&info[i].t, &info[i].d)
	}

	sort.Slice(info, func(i, j int) bool {
		return info[i].d > info[j].d
	})

	selected := info[:k]
	selectedOnly := make([]int, 0)
	selectedChohuku := make([]int, 0)
	unselectedOnly := make([]int, 0)
	memo := make(map[int]int)

	for _, p := range selected {
		if _, ok := memo[p.t]; !ok {
			memo[p.t] = 1
			selectedOnly = append(selectedOnly, p.d)
		} else {
			selectedChohuku = append(selectedChohuku, p.d)
		}
	}

	cntType := len(memo)
	for _, p := range info[k:] {
		if _, ok := memo[p.t]; !ok {
			memo[p.t] = 1
			unselectedOnly = append(unselectedOnly, p.d)
		}
	}

	sumSelect := sum(selectedChohuku) + sum(selectedOnly)
	ans := cntType*cntType + sumSelect

	sort.Slice(unselectedOnly, func(i, j int) bool {
		return unselectedOnly[i] > unselectedOnly[j]
	})
	for i := 0; i < min(len(selectedChohuku), len(unselectedOnly)); i++ {
		cntType++
		sumSelect += unselectedOnly[len(unselectedOnly)-1]
		sumSelect -= selectedChohuku[len(selectedChohuku)-1]
		unselectedOnly = unselectedOnly[:len(unselectedOnly)-1]
		selectedChohuku = selectedChohuku[:len(selectedChohuku)-1]
		tmp := cntType*cntType + sumSelect
		ans = max(ans, tmp)
	}
	fmt.Println(ans)
}

func sum(s []int) int {
	total := 0
	for _, v := range s {
		total += v
	}
	return total
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
