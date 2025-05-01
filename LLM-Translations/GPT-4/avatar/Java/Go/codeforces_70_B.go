Go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := scanner.Text()

	scanner.Scan()
	input := scanner.Text()

	var msgLength []int
	max := -1
	count := 0
	idx := 0

	splitInput := strings.Split(input, "")
	for i := 0; i < len(splitInput); i++ {
		c := splitInput[i]
		if c == "." || c == "?" || c == "!" {
			msgLength = append(msgLength, count+1)
			idx++
			if count+1 > max {
				max = count + 1
			}
			i++
			count = 0
		} else {
			count++
		}
	}

	if max > n {
		fmt.Println("Impossible")
	} else {
		ans := 0
		for i := 0; i < idx; i++ {
			l := msgLength[i]
			for i < idx-1 && l+msgLength[i+1]+1 <= n {
				l += msgLength[i+1] + 1
				i++
			}
			ans++
		}
		fmt.Println(ans)
	}
}
// //End of Code


Please note that the above Go code is assuming that 'n' is an integer in the given Java code. However, in this Go code, 'n' is considered as a string. You may need to convert it to an integer if required.
