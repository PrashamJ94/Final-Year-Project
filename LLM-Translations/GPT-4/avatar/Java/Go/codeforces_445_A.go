
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
	inp := strings.Split(scanner.Text(), " ")
	n := inp[0]
	m := inp[1]
	var ans []string

	for i := 0; i < n; i++ {
		scanner.Scan()
		str := scanner.Text()
		var temp strings.Builder

		for j := 0; j < m; j++ {
			if str[j] == '-' {
				temp.WriteString("-")
			} else {
				if (i+j)%2 == 1 {
					temp.WriteString("W")
				} else {
					temp.WriteString("B")
				}
			}
		}

		ans = append(ans, temp.String())
	}

	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}
// //End of Code

Please note that, unlike Java, Go does not throw exceptions, so error handling is done differently. You might need to add error checks where you think it's necessary. The above code assumes that the input will always be correct.
