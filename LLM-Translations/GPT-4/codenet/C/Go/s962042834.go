
package main

import "fmt"

func kansu(a int, b int, kouji [][]int) int {
	var suu [17][17]int
	for i := 1; i <= a; i++ {
		for j := 1; j <= b; j++ {
			if kouji[i][j] == 1 {
				suu[i][j] = 0
			} else {
				if i == 1 && j == 1 {
					suu[i][j] = 1
				} else {
					if i == 1 {
						suu[i][j] = suu[i][j-1]
					} else if j == 1 {
						suu[i][j] = suu[i-1][j]
					} else {
						suu[i][j] = suu[i][j-1] + suu[i-1][j]
					}
				}
			}
		}
	}
	return suu[a][b]
}

func main() {
	var a, b, n, x, y int
	fmt.Scanf("%d %d", &a, &b)

	for a != 0 && b != 0 {
		kouji := make([][]int, 17)
		for i := range kouji {
			kouji[i] = make([]int, 17)
		}

		fmt.Scanf("%d", &n)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d %d", &x, &y)
			kouji[x][y] = 1
		}

		fmt.Println(kansu(a, b, kouji))

		fmt.Scanf("%d %d", &a, &b)
	}
}

// 
