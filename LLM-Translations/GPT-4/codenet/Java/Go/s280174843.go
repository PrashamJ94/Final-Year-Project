package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var abc [3]int
	var str string
	var inp []string

	buf := bufio.NewReader(os.Stdin)
	str, _ = buf.ReadString('\n')
	str = strings.TrimSpace(str)
	inp = strings.Split(str, " ")

	for i := 0; i < len(inp); i++ {
		abc[i], _ = strconv.Atoi(inp[i])
	}

	if abc[0] < abc[1] && abc[1] < abc[2] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
