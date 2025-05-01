
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(x, t, a, b, da, db int) {
	first := 0
	second := 0
	ok := false

	for i := 0; i < t; i++ {
		first = a - (da * i)
		for j := 0; j < t; j++ {
			second = b - (db * j)
			if second+first == x || second == x || first == x || x == 0 {
				ok = true
				break
			}
		}
	}

	if ok {
		fmt.Print("YES")
	} else {
		fmt.Print("NO")
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	input, _ := reader.ReadString('\n')
	nums := strings.Fields(input)

	x, _ := strconv.Atoi(nums[0])
	t, _ := strconv.Atoi(nums[1])
	a, _ := strconv.Atoi(nums[2])
	b, _ := strconv.Atoi(nums[3])
	da, _ := strconv.Atoi(nums[4])
	db, _ := strconv.Atoi(nums[5])

	solve(x, t, a, b, da, db)
}

// //End of Code


