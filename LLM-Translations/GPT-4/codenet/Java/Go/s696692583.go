
package main

import (
	"fmt"
	"strings"
)

func main() {
	var my1, my2, enemy1 int
	for {
		_, err := fmt.Scan(&my1, &my2, &enemy1)
		if err != nil {
			break
		}
		used := make([]bool, 11)
		used[my1] = true
		used[my2] = true
		used[enemy1] = true
		all := 0
		safe := 0
		for i := 1; i <= 10; i++ {
			if !used[i] {
				all++
				if my1+my2+i <= 20 {
					safe++
				}
			}
		}
		if safe*2 >= all {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func solve(a [][]int) byte {
	s := []byte{'d', 'o', 'x'}
	for side := 1; side <= 2; side++ {
		for i := 0; i < 3; i++ {
			if a[i][0] == side && a[i][1] == side && a[i][2] == side {
				return s[side]
			}
			if a[0][i] == side && a[1][i] == side && a[2][i] == side {
				return s[side]
			}
		}
		if a[0][0] == side && a[1][1] == side && a[2][2] == side {
			return s[side]
		}
		if a[0][2] == side && a[1][1] == side && a[2][0] == side {
			return s[side]
		}
	}
	return 'd'
}

// 
