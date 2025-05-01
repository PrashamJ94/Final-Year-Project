package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	nums := strings.Split(scanner.Text(), " ")

	arr := []int{}
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(nums[i])
		if num == 1 {
			arr = append(arr, i)
		}
	}

	if len(arr) == 0 {
		fmt.Println(0)
	} else {
		result := 1
		for i := 1; i < len(arr); i++ {
			result *= arr[i] - arr[i-1]
		}
		fmt.Println(result)
	}
}

// //End of Code
