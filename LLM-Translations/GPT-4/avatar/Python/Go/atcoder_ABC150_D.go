package main

import (
	"fmt"
	"math"
	"strings"
	"strconv"
)

func GCD(a, b int) int {
    for b != 0 {
        a, b = b, a%b
    }
    return a
}

func main() {
	var n, num int
	fmt.Scan(&n, &num)
	
	numSet := make(map[int]bool)
	twoTimesSet := make(map[int]bool)

	var input string
	fmt.Scanln(&input)
	
	inputs := strings.Split(input, " ")
	for _, i := range inputs {
		number, _ := strconv.Atoi(i)
		numSet[number] = true
	}

	for i := range numSet {
		for j := 1; j < 30; j++ {
			i /= 2
			if i%2 != 0 {
				twoTimesSet[j] = true
				break
			}
		}
		if len(twoTimesSet) != 1 {
			fmt.Println(0)
			break
		}
	}

	if len(twoTimesSet) == 1 {
		numList := make([]int, 0, len(numSet))
		for k := range numSet {
			numList = append(numList, k)
		}

		lcm := numList[0]
		for i := 1; i < len(numList); i++ {
			lcm = lcm * numList[i] / GCD(lcm, numList[i])
		}
		fmt.Println((num - lcm/2) / lcm + 1)
	}
}

// End of Code
