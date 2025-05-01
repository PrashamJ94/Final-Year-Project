package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	
	scanner.Scan()
	arr := scanner.Text()
	numbers := strings.Fields(arr)
	
	var intNumbers []int
	for _, number := range numbers {
		num, _ := strconv.Atoi(number)
		intNumbers = append(intNumbers, num)
	}
	
	sort.Ints(intNumbers)
	
	result := -1
	if allDivisible(intNumbers, intNumbers[0]) {
		result = intNumbers[0]
	}
	
	fmt.Println(result)
}

func allDivisible(numbers []int, divisor int) bool {
	for _, number := range numbers {
		if number % divisor != 0 {
			return false
		}
	}
	return true
}

// End of Code
