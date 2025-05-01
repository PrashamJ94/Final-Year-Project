
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
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))
	wStr, _ := reader.ReadString('\n')
	wStr = strings.TrimSpace(wStr)
	wArr := strings.Split(wStr, " ")
	c := 2
	for _, iStr := range wArr {
		i, _ := strconv.Atoi(iStr)
		if i == 1 {
			fmt.Println(c)
		} else if i%2 == 0 {
			c = 3 - c
			fmt.Println(c)
		} else {
			fmt.Println(c)
		}
	}
}
// End of Code


