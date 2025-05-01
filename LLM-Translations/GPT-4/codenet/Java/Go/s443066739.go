package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	pre := make([]int64, n+1)

	scanner.Scan()
	line := scanner.Text()
	nums := strings.Fields(line)

	for i := 1; i <= n; i++ {
		num, _ := strconv.ParseInt(nums[i-1], 10, 64)
		pre[i] = pre[i-1] + num
	}

	min := int64(math.MaxInt64)

	for i := 1; i < n; i++ {
		val1 := pre[i]
		val2 := pre[n] - pre[i]

		min = int64(math.Min(float64(min), math.Abs(float64(val1-val2))))
	}

	fmt.Println(min)
}
// 
