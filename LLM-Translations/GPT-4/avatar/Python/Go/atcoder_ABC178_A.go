package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func solve(tc int) {
	reader := bufio.NewReader(os.Stdin)
	aStr, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(strings.TrimSpace(aStr))

	if a == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	tcs := 1
	tc := 1
	for tc <= tcs {
		solve(tc)
		tc++
	}
}
// End of Code
