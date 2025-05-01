
package main

import (
	"fmt"
	"sort"
	"strings"
)

func run(s, t string) string {
	ss := frequencyCount(s)
	tt := frequencyCount(t)

	sort.Ints(ss)
	sort.Ints(tt)

	if equal(ss, tt) {
		return "Yes"
	} else {
		return "No"
	}
}

func frequencyCount(s string) []int {
	frequency := make(map[rune]int)
	for _, char := range s {
		frequency[char]++
	}

	values := make([]int, 0, len(frequency))
	for _, value := range frequency {
		values = append(values, value)
	}

	return values
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	fmt.Println(run(s, t))
}
// End of Code

This Go code does the same thing as the provided Python code. It counts the frequency of each character in the input strings, sorts the frequency counts, and then checks if the frequency counts are the same for the two strings. If they are, it returns "Yes", otherwise it returns "No".
