package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)
	var N int
	fmt.Scanf("%d\n", &N)
	c, _ := scanner.ReadString('\n')
	c = strings.TrimSpace(c)
	result := make([]byte, len(c))
	for i := 0; i < len(c); i++ {
		result[i] = byte((c[i]-'A'+byte(N)) % 26 + 'A')
	}
	fmt.Println(string(result))
}
// 
