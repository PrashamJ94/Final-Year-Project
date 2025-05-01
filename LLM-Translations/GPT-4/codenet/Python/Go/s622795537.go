package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	arr := make(map[string]int)

	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()

		if _, ok := arr[s]; !ok {
			arr[s] = 1
		} else {
			arr[s]++
		}
	}

	maxCount := 0
	for _, v := range arr {
		if v > maxCount {
			maxCount = v
		}
	}

	var dic []string
	for k, v := range arr {
		if v == maxCount {
			dic = append(dic, k)
		}
	}

	sort.Strings(dic)
	for _, v := range dic {
		fmt.Println(v)
	}
}
// 
