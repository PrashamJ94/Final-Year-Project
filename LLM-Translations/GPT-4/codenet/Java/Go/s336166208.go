package main

import (
	"fmt"
	"strconv"
)

func main() {
	var info [4][3][10]int

	var n, built, floor, room, num int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&built, &floor, &room, &num)
		info[built-1][floor-1][room-1] += num
	}

	for i := 0; i < 4; i++ {
		for j := 0; j < 3; j++ {
			for k := 0; k < 10; k++ {
				fmt.Print(" " + strconv.Itoa(info[i][j][k]))
			}
			fmt.Print("\n")
		}
		if i != 4-1 {
			fmt.Print("####################\n")
		}
	}
}

// 
