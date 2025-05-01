package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	x_temp := strings.Fields(scanner.Text())
	x := make([]int, len(x_temp))
	for i, v := range x_temp {
		x[i], _ = strconv.Atoi(v)
	}

	a := make([]int, 0)
	b := make([]int, 0)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	cnta := make([]int, 100002+1)
	cntb := make([]int, 100002+1)
	vala := 0
	vala1 := 0
	maxCnta := 0
	maxCnta1 := 0
	for _, i := range a {
		cnta[i]++
	}
	for _, i := range a {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}
	for _, i := range a {
		if maxCnta1 < cnta[i] && vala != i {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}
	valb := 0
	valb1 := 0
	maxCntb := 0
	maxCntb1 := 0
	for _, i := range b {
		cntb[i]++
	}
	for _, i := range b {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}
	for _, i := range b {
		if maxCntb1 < cntb[i] && valb != i {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}
	if valb != vala {
		res := 0
		for _, i := range a {
			if i != vala {
				res++
			}
		}
		for _, i := range b {
			if i != valb {
				res++
			}
		}
		fmt.Println(res)
	} else {
		resa := 0
		resb := 0
		resa1 := 0
		resb1 := 0
		for _, i := range a {
			if i != vala {
				resa++
			}
			if i != vala1 {
				resa1++
			}
		}
		for _, i := range b {
			if i != valb {
				resb++
			}
			if i != valb1 {
				resb1++
			}
		}
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}
// End of Code

This Go code does the same thing as the provided Python code. It uses the bufio package to read input, which is faster than the standard fmt.Scanln() function. The strconv package is used to convert string input to integers, and the strings package is used to split the input string into individual numbers. The rest of the code is a direct translation of the Python code.
