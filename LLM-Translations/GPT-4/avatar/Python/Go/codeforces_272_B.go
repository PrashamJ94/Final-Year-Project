package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	numbersInput, _ := reader.ReadString('\n')
	numbers := toIntSlice(strings.Fields(numbersInput))
	fmt.Println(nPairsWithCommonFX(numbers))
}

func toIntSlice(stringSlice []string) []int {
	intSlice := make([]int, len(stringSlice))
	for i, v := range stringSlice {
		intSlice[i], _ = strconv.Atoi(v)
	}
	return intSlice
}

func nPairsWithCommonFX(sequence []int) int {
	storage := make(map[int][]int)
	FXs := []int{}
	for _, value := range sequence {
		y := f(value)
		storage[y] = append(storage[y], value)
		if len(storage[y]) == 1 {
			FXs = append(FXs, y)
		}
	}
	sum := 0
	for _, y := range FXs {
		sum += len(storage[y]) * len(storage[y])
	}
	return (sum - len(sequence)) / 2
}

func f(n int) int {
	y := 1
	for n != 1 {
		if n%2 != 0 {
			y++
		}
		n /= 2
	}
	return y
}
// End of Code
