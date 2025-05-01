
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func mul(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
	for *idx+1 < len(str) && str[*idx+1] == '*' {
		*idx += 2
		val, _ := strconv.Atoi(string(str[*idx]))
		res *= val
	}
	return res
}

func add(str string, idx *int) int {
	res := mul(str, idx)
	for *idx+1 < len(str) && str[*idx+1] == '+' {
		*idx += 2
		res += mul(str, idx)
	}
	return res
}

func bob(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
	for *idx+1 < len(str) {
		if str[*idx+1] == '+' {
			val, _ := strconv.Atoi(string(str[*idx+2]))
			res += val
		} else {
			val, _ := strconv.Atoi(string(str[*idx+2]))
			res *= val
		}
		*idx += 2
	}
	return res
}

func main() {
	var s string
	var d int
	for {
		n, _ := fmt.Scan(&s, &d)
		if n == 0 {
			break
		}
		idx := 0
		a := add(s, &idx)
		idx = 0
		b := bob(s, &idx)
		if a == d {
			if b == d {
				fmt.Println("U")
			} else {
				fmt.Println("M")
			}
		} else {
			if b == d {
				fmt.Println("L")
			} else {
				fmt.Println("I")
			}
		}
	}
}

// 
