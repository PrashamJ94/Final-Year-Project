
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	pmin := 1000
	mmin := 0
	s = "0" + s
	for i := len(s) - 1; i >= 0; i-- {
		v, _ := strconv.Atoi(string(s[i]))
		npmin := min(pmin+10-(v+1), mmin+10-v)
		nmmin := min(pmin+v+1, mmin+v)
		pmin = npmin
		mmin = nmmin
	}
	fmt.Println(min(pmin, mmin))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// End of Code

The above Go code does not include the functionality of the Python code related to input methods and testing, as these concepts are not typically used in Go in the same way. The Go code focuses on the primary functionality of the provided Python code, which is to process the string `s` and print a result. The conversion from string to integer is handled by the `strconv.Atoi` function in Go, and a `min` function is defined to replicate the behavior of Python's `min` function.
