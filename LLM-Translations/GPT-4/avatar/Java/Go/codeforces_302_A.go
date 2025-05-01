
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
	parts := strings.Fields(scanner.Text())
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])
	arr := make([]int, n)
	scanner.Scan()
	parts = strings.Fields(scanner.Text())
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(parts[i])
	}
	var res strings.Builder
	o := 0
	e := 0
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}
	for i := 0; i < k; i++ {
		scanner.Scan()
		parts = strings.Fields(scanner.Text())
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		if (r-l+1)%2 == 1 {
			res.WriteString("0\n")
		} else {
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res.WriteString("1\n")
			} else {
				res.WriteString("0\n")
			}
		}
	}
	fmt.Print(res.String())
}

// //End of Code

