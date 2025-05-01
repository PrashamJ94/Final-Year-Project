package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(input), " ")
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	c := 0
	for i := 0; i < 2; i++ {
		c += max(a, b)
		if a >= b {
			a -= 1
		} else {
			b -= 1
		}
	}
	fmt.Println(c)
} //End of Code
