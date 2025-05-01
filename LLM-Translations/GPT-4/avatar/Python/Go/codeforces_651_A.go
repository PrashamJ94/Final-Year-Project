package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	result := Max(x+y-3+((y-x)%3 > 0), 0)
	fmt.Println(result)

	num_inp := func() int {
		var num int
		fmt.Scan(&num)
		return num
	}

	arr_inp := func() []int {
		var s string
		fmt.Scan(&s)
		strs := strings.Split(s, " ")
		nums := make([]int, len(strs))
		for i, str := range strs {
			nums[i], _ = strconv.Atoi(str)
		}
		return nums
	}

	sp_inp := func() (int, int) {
		var a, b int
		fmt.Scan(&a, &b)
		return a, b
	}

	str_inp := func() string {
		var str string
		fmt.Scan(&str)
		return str
	}
}

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
// End of Code
