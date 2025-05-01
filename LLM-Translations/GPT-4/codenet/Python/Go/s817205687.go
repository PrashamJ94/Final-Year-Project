
package main

import (
	"fmt"
	"math"
)

func lcm(x, y int) int {
	return (x * y) / gcd(x, y)
}

func gcd(x, y int) int {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

func lcm_list(numbers []int) int {
	res := 1
	for _, num := range numbers {
		res = lcm(res, num)
	}
	return res
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	for i := 0; i < N; i++ {
		A[i] = A[i] / 2
	}

	count_div_2 := -1
	for _, a := range A {
		cnt := 0
		for a%2 == 0 {
			a /= 2
			cnt++
		}
		if count_div_2 == -1 {
			count_div_2 = cnt
		} else if cnt != count_div_2 {
			fmt.Println(0)
			return
		}
	}

	my_lcm := lcm_list(A)
	if my_lcm > M {
		fmt.Println(0)
		return
	}

	tmp := M / my_lcm
	ans := (tmp + 1) / 2
	fmt.Println(ans)
}


