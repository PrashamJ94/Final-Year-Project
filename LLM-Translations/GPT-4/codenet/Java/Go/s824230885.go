package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	listStr := scanner.Text()
	list := toIntArray(strings.Split(listStr, " "))

	max := 0
	output := 0
	for i := 0; i < N; i++ {
		if max <= list[i] {
			max = list[i]
			output++
		}
	}
	fmt.Println(output)
}

func toIntArray(arr []string) []int {
	newArr := make([]int, len(arr))
	for i, v := range arr {
		newArr[i], _ = strconv.Atoi(v)
	}
	return newArr
}

// 
