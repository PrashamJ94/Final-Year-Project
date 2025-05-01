package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	nums := strings.Split(input, " ")

	h, _ := strconv.Atoi(nums[0])
	a, _ := strconv.Atoi(nums[1])

	num := 0
	for i := 1; h > 0; i++ {
		h = h - a
		num++
	}

	fmt.Println(num)
}

// //End of Code.
