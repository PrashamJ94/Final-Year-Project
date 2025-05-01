package main

import (
	"fmt"
	"strconv"
)

func twosInFactorial(n int) int {
	return n - strconv.Count(strconv.FormatInt(int64(n), 2), "1")
}

func parityOfNCr(n, i int) bool {
	f := twosInFactorial
	return f(n)-f(n-i)-f(i) > 0
}

func main() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := range nums {
		fmt.Scan(&nums[i])
		nums[i] -= 1
	}
	noOne := true
	for _, num := range nums {
		if num == 1 {
			noOne = false
			break
		}
	}
	if noOne {
		for i := range nums {
			nums[i] /= 2
		}
	}
	isOdd := false
	for i, num := range nums {
		if !parityOfNCr(n-1, i) && num&1 != 0 {
			isOdd = !isOdd
		}
	}
	if !isOdd {
		fmt.Println(0)
	} else {
		if noOne {
			fmt.Println(1)
		} else {
			fmt.Println(2)
		}
	}
}
// End of Code


Please note that, while Python uses the `<<` shift operator to multiply a number by a power of 2, Go does not have an equivalent operation. Instead, you can use an if-else structure to check whether the `noOne` variable is true and print 1 if it is, or 2 if it is not.
