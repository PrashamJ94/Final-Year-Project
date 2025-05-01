package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var y int
	fmt.Scan(&y)

	var input string
	fmt.Scan(&input)
	arrStr := strings.Split(input, " ")
	arr := make([]int, len(arrStr))
	for i, v := range arrStr {
		arr[i], _ = strconv.Atoi(v)
	}

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr); j++ {
			if i == j {
				continue
			}
			for k := 0; k < len(arr); k++ {
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i]+arr[j] {
					fmt.Println(k+1, j+1, i+1)
					os.Exit(0)
				}
			}
		}
	}
	fmt.Println(-1)
}

// End of Code
