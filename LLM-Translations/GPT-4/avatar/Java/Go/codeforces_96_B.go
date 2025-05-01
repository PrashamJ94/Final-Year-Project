
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var number int64
	fmt.Scan(&number)

	var ans int64 = -1
	var value int64 = 0
	var mask int = 2

	for value < number {
		s := strconv.FormatInt(int64(mask), 2)[1:]
		mask++

		var zeros int = 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}

		if zeros != len(s)-zeros {
			continue
		}

		s = strings.ReplaceAll(s, "0", "4")
		s = strings.ReplaceAll(s, "1", "7")
		value, _ = strconv.ParseInt(s, 10, 64)
	}

	fmt.Println(value)
}

// //End of Code


