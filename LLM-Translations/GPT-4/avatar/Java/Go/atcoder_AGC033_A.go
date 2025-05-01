package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var H, W int
	fmt.Scanf("%d %d", &H, &W)
	A := make([][]byte, H)
	for i := 0; i < H; i++ {
		scanner.Scan()
		A[i] = []byte(scanner.Text())
	}
	queue := make([][3]int, 0, H*W)
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if A[i][j] == '#' {
				queue = append(queue, [3]int{i, j, 0})
			}
		}
	}
	flag := make([][]int, H)
	for i := range flag {
		flag[i] = make([]int, W)
	}
	ans := 0
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}
	for len(queue) > 0 {
		temp := queue[0]
		queue = queue[1:]
		y, x, depth := temp[0], temp[1], temp[2]
		for i := 0; i < 4; i++ {
			ny, nx := y+dy[i], x+dx[i]
			if 0 <= ny && ny <= H-1 && 0 <= nx && nx <= W-1 {
				if flag[ny][nx] == 0 && A[ny][nx] == '.' {
					flag[ny][nx] = 1
					queue = append(queue, [3]int{ny, nx, depth + 1})
					ans = depth + 1
				}
			}
		}
	}
	fmt.Println(ans)
}
// //End of Code.
