package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	input := ""
	fmt.Scan(&input)
	a := strings.Split(input, " ")

	var b []string

	b = append(reverse(a[1::2]), a[::2]...)
	if len(a)%2 == 0 {
		fmt.Println(strings.Join(b, " "))
	} else {
		fmt.Println(strings.Join(reverse(b), " "))
	}
	// 
}

func reverse(s []string) []string {
	result := make([]string, len(s))
	copy(result, s)
	for i := len(s)/2 - 1; i >= 0; i-- {
		opp := len(s) - 1 - i
		result[i], result[opp] = s[opp], s[i]
	}
	return result
}

func ::(s []string, step int) []string {
	result := make([]string, len(s)/step)
	for i := 0; i < len(s); i += step {
		result[i/step] = s[i]
	}
	return result
}

