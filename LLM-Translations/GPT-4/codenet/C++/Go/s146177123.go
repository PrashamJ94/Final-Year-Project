
package main

import (
	"fmt"
)

var seg = [][]bool{
	{false, true, true, true, true, true, true},
	{false, false, false, false, true, true, false},
	{true, false, true, true, false, true, true},
	{true, false, false, true, true, true, true},
	{true, true, false, false, true, true, false},

	{true, true, false, true, true, false, true},
	{true, true, true, true, true, false, true},
	{false, true, false, false, true, true, true},
	{true, true, true, true, true, true, true},
	{true, true, false, true, true, true, true},
}

func main() {
	var n, t int
	var st [7]bool
	for {
		fmt.Scan(&n)
		if n == -1 {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&t)
			var ans [7]byte
			for i := 0; i < 7; i++ {
				if st[i] != seg[t][i] {
					ans[i] = '1'
				} else {
					ans[i] = '0'
				}
				st[i] = seg[t][i]
			}
			fmt.Println(string(ans[:]))
		}
	}
}

// 
