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
	str := strings.Split(scanner.Text(), " ")
	scanner.Scan()
	st := strings.Split(scanner.Text(), " ")
	a, _ := strconv.Atoi(st[0])
	b, _ := strconv.Atoi(st[1])
	scanner.Scan()
	u := scanner.Text()

	if u == str[0] {
		fmt.Printf("%d %d", a-1, b)
	} else {
		fmt.Printf("%d %d", a, b-1)
	}
}

// //End of Code
