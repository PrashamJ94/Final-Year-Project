
package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	nums := strings.Fields(scanner.Text())
	
	counts := make(map[int]int)
	c := 0

	for _, num := range nums {
		numInt, _ := strconv.Atoi(num)
		counts[numInt]++
	}
	
	for i := range counts {
		if i == 0 {
			c += counts[i] * (counts[i] - 1)
		} else {
			if counts[-i] > 0 {
				c += counts[i] * counts[-i]
			}
		}
	}
	
	fmt.Println(c / 2)
}

// End of Code.

Please note that Go handles user input differently than Python. The above Go code uses the bufio package to read from stdin. Also, unlike Python, Go does not have a built-in Counter type, so we use a map to keep track of counts.
