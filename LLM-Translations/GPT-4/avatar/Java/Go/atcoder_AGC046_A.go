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
	x, _ := strconv.Atoi(scanner.Text())
	count := 0
	tmp := x
	x = 0
	for x != 360 {
		x += tmp
		if x > 360 {
			x -= 360
		}
		count++
	}
	fmt.Println(count)
}

// //End of Code.
