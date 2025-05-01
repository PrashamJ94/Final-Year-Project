package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	list := strings.Split(strings.TrimSpace(line), " ")

	x, _ := strconv.Atoi(list[0])
	a, _ := strconv.Atoi(list[1])
	y, _ := strconv.Atoi(list[2])

	h := "NO"

	if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
		if x+y+a == 17 {
			h = "YES"
		}
	}

	fmt.Println(h)
}

// //End of Code.
