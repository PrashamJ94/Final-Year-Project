package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	parts := strings.Fields(text)
	vamshi, _ := strconv.Atoi(parts[0])
	z, _ := strconv.Atoi(parts[1])
	fmt.Println((vamshi/z + 1) * z)
}

// End of Code
