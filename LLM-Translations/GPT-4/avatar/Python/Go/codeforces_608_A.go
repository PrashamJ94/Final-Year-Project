
package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	params := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(params[0])
	s, _ := strconv.Atoi(params[1])

	c := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		ft := strings.Split(scanner.Text(), " ")
		f, _ := strconv.Atoi(ft[0])
		t, _ := strconv.Atoi(ft[1])

		x := t - (s - f)
		if x > c {
			c = x
		}
	}
	fmt.Println(s + c)
}
// End of code


