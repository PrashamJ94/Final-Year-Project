package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}
	B := counter(a)
	k := getKeys(B)
	v := getValues(B)

	if len(B) == 3 && k[0]^k[1]^k[2] == 0 && v[0] == v[1] && v[1] == v[2] {
		fmt.Println("Yes")
	} else if len(B) == 2 && indexOf(0, k) != -1 {
		zeroIndex := indexOf(0, k)
		otherIndex := 1 - zeroIndex
		if v[zeroIndex] == 2*v[otherIndex] || v[otherIndex] == 2*v[zeroIndex] {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	} else if len(B) == 1 && k[0] == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func counter(a []int) map[int]int {
	res := make(map[int]int)
	for _, v := range a {
		res[v]++
	}
	return res
}

func getKeys(m map[int]int) []int {
	res := make([]int, 0, len(m))
	for k := range m {
		res = append(res, k)
	}
	sort.Ints(res)
	return res
}

func getValues(m map[int]int) []int {
	res := make([]int, 0, len(m))
	for _, v := range m {
		res = append(res, v)
	}
	sort.Ints(res)
	return res
}

func indexOf(n int, arr []int) int {
	for i, v := range arr {
		if v == n {
			return i
		}
	}
	return -1
}

// 
