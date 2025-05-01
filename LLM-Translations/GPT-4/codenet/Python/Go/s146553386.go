package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([][]int, 2)
	for i := 0; i < 2; i++ {
		a[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&a[i][j])
		}
	}
	a[1] = reverse(a[1])

	res_0 := cumSum(a[0])
	res_1 := cumSum(a[1])

	ans := 0
	for i := 0; i < n; i++ {
		check := res_0[i] + res_1[n-1-i]
		if check > ans {
			ans = check
		}
	}
	fmt.Println(ans)
}

func reverse(arr []int) []int {
	length := len(arr)
	for i := 0; i < length/2; i++ {
		arr[i], arr[length-1-i] = arr[length-1-i], arr[i]
	}
	return arr
}

func cumSum(arr []int) []int {
	result := make([]int, len(arr))
	result[0] = arr[0]
	for i := 1; i < len(arr); i++ {
		result[i] = result[i-1] + arr[i]
	}
	return result
}

// 
