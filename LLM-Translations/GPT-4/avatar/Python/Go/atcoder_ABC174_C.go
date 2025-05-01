
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	t := 0
	for i := 1; i <= k; i++ {
		t = (t % k) * 10 + 7
		if t % k == 0 {
			fmt.Println(i)
			return
		}
	}
	fmt.Println(-1)
}
// End of Code


The Go code reads an integer from standard input, then runs a loop from 1 to the input number. It calculates a new value for `t` in each iteration, and if `t` modulo `k` is 0, it prints the current loop counter and exits. If the loop finishes without finding such a number, it prints `-1`.
