
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
	n, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		s = strings.Replace(s, "Hoshino", "Hoshina", -1)
		fmt.Println(s)
	}
}

// 
