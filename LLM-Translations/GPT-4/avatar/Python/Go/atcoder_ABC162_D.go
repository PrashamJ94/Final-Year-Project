package main

import (
	"fmt"
	"strings"
	"math"
)

func count(s string, char rune) int {
	counter := 0
	for _, r := range s {
		if r == char {
			counter++
		}
	}
	return counter
}

func calculate(n int, s string) {
	arr := strings.Split(s, "")
	rNum := count(s, 'R')
	gNum := count(s, 'G')
	bNum := count(s, 'B')
	sum := 0
	for step := 1; step <= int(math.Ceil(float64(n)/2))+1; step++ {
		for i := 0; i < n-2*step; i++ {
			s := strings.Join([]string{arr[i], arr[i+step], arr[i+step*2]}, "")
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum++
			}
		}
	}
	fmt.Println(rNum * gNum * bNum - sum)
}

func main() {
	var N int
	var S string
	fmt.Scan(&N)
	fmt.Scan(&S)
	calculate(N, S)
}
// End of Code


Please note, in the above Go code, we are using `fmt.Scan()` to take the input from the user. In Go, the `input()` function does not exist as it does in Python. Also, the 'count' function is created to mimic the count() function behavior of Python in Go.
