
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func not(x int) int {
	return 2 - x
}

func and(x, y int) int {
	if x*y == 0 {
		return 0
	}
	if x == 2 && y == 2 {
		return 2
	}
	return 1
}

func or(x, y int) int {
	if x == 2 || y == 2 {
		return 2
	}
	if x == 1 || y == 1 {
		return 1
	}
	return 0
}

func parse(ss string, it *int) int {
	c := ss[*it]
	*it++

	if '0' <= c && c <= '2' {
		return int(c - '0')
	}
	if c == '-' {
		return not(parse(ss, it))
	}

	x := parse(ss, it)
	c = ss[*it]
	*it++
	y := parse(ss, it)
	*it++
	if c == '*' {
		return and(x, y)
	}
	return or(x, y)
}

func main() {
	var input, ss string
	var a [3]int
	var it, cnt int

	for {
		fmt.Scan(&input)

		if input == "." {
			break
		}

		for i := 0; i < 3; i++ {
			a[i] = i
		}
		cnt = 0

		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a[0] = i
					a[1] = j
					a[2] = k
					ss = input
					for index, c := range ss {
						if c == 'P' {
							ss = ss[:index] + strconv.Itoa(a[0]) + ss[index+1:]
						}
						if c == 'Q' {
							ss = ss[:index] + strconv.Itoa(a[1]) + ss[index+1:]
						}
						if c == 'R' {
							ss = ss[:index] + strconv.Itoa(a[2]) + ss[index+1:]
						}
					}
					it = 0
					if parse(ss, &it) == 2 {
						cnt++
					}
				}
			}
		}
		fmt.Println(cnt)
	}
}

// 
