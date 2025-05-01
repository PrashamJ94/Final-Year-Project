
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pair struct {
	first  int64
	second int64
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	inputs := strings.Fields(input)
	a := make([]int64, 4)

	for i := 0; i < 4; i++ {
		a[i], _ = strconv.ParseInt(inputs[i], 10, 64)
	}

	fmt.Println(max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2]))))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// //End of Code


