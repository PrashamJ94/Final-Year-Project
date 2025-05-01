
package main

import (
	"fmt"
)

const MAX = 21

var n, x, y int
var fld [MAX][MAX]int

func main() {
	var m int
	for {
		_, err := fmt.Scan(&n)
		if err != nil || n == 0 {
			break
		}
		init(n)
		fmt.Scan(&m)
		move(m)
		if n == 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func init(i int) {
	var a, b int
	x, y = 10, 10
	fld = [MAX][MAX]int{}
	for i > 0 {
		fmt.Scan(&a, &b)
		fld[b][a] = 1
		i--
	}
}

func move(i int) {
	var a, d int
	var buf string
	for i > 0 {
		fmt.Scan(&buf, &a)
		switch buf {
		case "N":
			d = 0
		case "E":
			d = 1
		case "S":
			d = 2
		case "W":
			d = 3
		}
		for a > 0 {
			if d%2 == 0 {
				if d == 0 {
					y++
				} else {
					y--
				}
			} else {
				if d == 1 {
					x++
				} else {
					x--
				}
			}
			if fld[y][x] == 1 {
				fld[y][x] = 0
				n--
			}
			a--
		}
		i--
	}
}

// 
