package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Print("Enter number: ")
	scanner.Scan()
	var n int
	fmt.Sscan(scanner.Text(), &n)
	q := make([][]string, n)
	count := 0
	
	for i := 0; i < n; i++ {
		fmt.Print("Enter string: ")
		scanner.Scan()
		q[i] = strings.Fields(scanner.Text())
	}
	
	for _, j := range q {
		for _, k := range q {
			if k == j {
				continue
			} else if j[0] == k[len(k)-1] {
				count++
			} else {
				continue
			}
		}
	}
	fmt.Println(count)
}

// End of Code
