package main

import (
	"fmt"
)

var d int
var n int
var mapArr [105]string
var dx = [4]int{0, 1, 0, -1}
var dy = [4]int{-1, 0, 1, 0}
var ab = [4]int{2, 2, 2, 2}

func visit() {
	flg := 0
	x, y := 2, n
	mapArr[y] = mapArr[y][:x] + " " + mapArr[y][x+1:]
	var sum int

	for {
		sum = 0
		for {
			if mapArr[y+dy[flg]*2][x+dx[flg]*2] != '#' && mapArr[y+dy[flg]][x+dx[flg]] != ' ' {
				flg++
				break
			}

			mapArr[y+dy[flg]] = mapArr[y+dy[flg]][:x+dx[flg]] + " " + mapArr[y+dy[flg]][x+dx[flg]+1]
			y = y + dy[flg]
			x = x + dx[flg]
			sum++
		}
		if flg == 4 {
			flg = 0
		}
		if sum == 0 {
			break
		}
		ab[0] = ab[1]
		ab[1] = ab[2]
		ab[2] = sum
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
			break
		}
	}
}

func main() {
	fmt.Scan(&d)

	for l := 0; l < d; l++ {
		fmt.Scan(&n)

		if n == 1 {
			fmt.Println("#")
			if l != d-1 {
				fmt.Println()
			}
			continue
		}

		for i := 0; i <= n+1; i++ {
			var str string
			for j := 0; j <= n+1; j++ {
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					str += "."
				} else {
					str += "#"
				}
			}
			mapArr[i] = str
		}

		visit()

		for i := 1; i <= n; i++ {
			fmt.Println(mapArr[i][1 : len(mapArr[i])-1])
		}
		if l != d-1 {
			fmt.Println()
		}
	}
}

// 
