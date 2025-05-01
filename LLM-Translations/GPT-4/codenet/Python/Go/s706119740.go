package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	candyStr := strings.Split(input, " ")
	candy := make([]int, len(candyStr))

	for i, s := range candyStr {
		candy[i], _ = strconv.Atoi(s)
	}

	sort.Ints(candy)

	if candy[0]+candy[1] == candy[2] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
