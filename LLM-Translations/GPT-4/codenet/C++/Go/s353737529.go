
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	s := ""

	if n == 0 {
		fmt.Println("0")
		return
	}

	for n != 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}

		n -= int(math.Abs(float64(n % 2)))

		n /= -2
	}

	s = Reverse(s)

	fmt.Println(s)
}

func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}


