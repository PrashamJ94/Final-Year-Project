Here is a translation of the provided Java code into Go:


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
	
	numMap := make(map[int]int)
	for i := 0; i < n; i++ {
		scanner.Scan()
		val, _ := strconv.Atoi(scanner.Text())
		numMap[val]++
	}
	
	max := 0
	for _, val := range numMap {
		if val > max {
			max = val
		}
	}
	
	fmt.Println(max, len(numMap))
}

// //End of Code


Please note that error handling is not implemented in this translation as it was not present in the original Java code. In a production code, you should always handle errors appropriately.
