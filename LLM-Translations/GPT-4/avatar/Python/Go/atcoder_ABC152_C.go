package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)
	
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	
	n := make([]int, N)
	for i, v := range strings.Fields(scanner.Text()) {
		n[i], _ = strconv.Atoi(v)
	}
	
	a := 1
	pos := 0
	for i := 1; i < N; i++ {
		if n[pos] > n[i] {
			a += 1
			pos = i
		}
	}
	fmt.Println(a)
}
// End of Code


Please note that Go doesn't have direct equivalent of numpy array so we are using slice in this case. For the same reason Go doesn't have equivalent to numpy's argmin function and we're using a loop to find the minimum value's index.
