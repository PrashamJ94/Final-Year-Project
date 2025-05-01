package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	a := make([]int, n)
	for i, val := range strings.Split(scanner.Text(), " ") {
		a[i], _ = strconv.Atoi(val)
	}

	count := bubbleSort(a, n)
	for i := 0; i < n; i++ {
		if i < n-1 {
			fmt.Print(a[i], " ")
		} else {
			fmt.Println(a[i])
		}
	}
	fmt.Println(count)
}

func bubbleSort(a []int, n int) int {
	flag := true
	count := 0
	for flag {
		flag = false
		for j := n - 1; j > 0; j-- {
			if a[j] < a[j-1] {
				a[j], a[j-1] = a[j-1], a[j]
				count++
				flag = true
			}
		}
	}
	return count
}
// 
