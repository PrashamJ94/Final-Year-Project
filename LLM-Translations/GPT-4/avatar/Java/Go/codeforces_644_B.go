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
	input := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(input[0])
	b, _ := strconv.Atoi(input[1])

	var ans = make([]int64, n)
	var q []int64

	for i := 0; i < n; i++ {
		scanner.Scan()
		input = strings.Split(scanner.Text(), " ")
		t, _ := strconv.Atoi(input[0])
		d, _ := strconv.Atoi(input[1])

		for len(q) > 0 && q[0] <= int64(t) {
			q = q[1:]
		}

		if len(q) <= b {
			var last int64
			if len(q) == 0 {
				last = int64(t)
			} else {
				last = q[len(q)-1]
			}
			ans[i] = last + int64(d)
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}

	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
}

// //End of Code
