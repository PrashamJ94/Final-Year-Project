package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	arrStr := strings.Fields(scanner.Text())
	arr := make([]int, n)
	for i := range arr {
		arr[i], _ = strconv.Atoi(arrStr[i])
	}
	if arr[0] > 15 {
		fmt.Println(15)
	} else {
		for i := 1; i < len(arr); i++ {
			if arr[i] - arr[i - 1] > 15 {
				fmt.Println(arr[i - 1] + 15)
				return
			}
		}
		if arr[len(arr) - 1] == 90 || arr[len(arr) - 1] + 15 >= 90 {
			fmt.Println(90)
		} else {
			fmt.Println(arr[len(arr) - 1] + 15)
		}
	}
}

// End of Code
