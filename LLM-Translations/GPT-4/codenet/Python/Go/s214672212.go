package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	numStrs := strings.Split(input, " ")
	nums := make([]int, len(numStrs))

	for i, numStr := range numStrs {
		num, _ := strconv.Atoi(numStr)
		nums[i] = num
	}

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})

	result := nums[0]*10 + nums[1] + nums[2]
	fmt.Println(result)
}
// 
