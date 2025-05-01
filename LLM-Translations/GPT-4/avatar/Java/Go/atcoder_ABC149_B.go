
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	tokens := strings.Split(strings.TrimSpace(input), " ")
	A, _ := strconv.ParseInt(tokens[0], 10, 64)
	B, _ := strconv.ParseInt(tokens[1], 10, 64)
	K, _ := strconv.ParseInt(tokens[2], 10, 64)

	x, y := atcoder_ABC149_B(A, B, K)

	fmt.Println(x, y)
}

func atcoder_ABC149_B(A, B, K int64) (x, y int64) {
	x = A
	y = B
	x = A - K
	if x < 0 {
		y = B + x
		x = 0
		if y < 0 {
			y = 0
		}
	}
	return x, y
}

//End of Code.
