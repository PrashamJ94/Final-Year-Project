
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	H, _ := strconv.Atoi(input[0])
	W, _ := strconv.Atoi(input[1])

	var G []string
	for i := 0; i < H+2; i++ {
		if i == 0 || i == H+1 {
			G = append(G, strings.Repeat("#", W+2))
		} else {
			scanner.Scan()
			G = append(G, "#"+scanner.Text()+"#")
		}
	}

	ans := 0
	for sx := 0; sx < W+2; sx++ {
		for sy := 0; sy < H+2; sy++ {
			if G[sy][sx] == '.' {
				dist := make([][]int, H+2)
				visited := make([][]int, H+2)
				for i := range dist {
					dist[i] = make([]int, W+2)
					visited[i] = make([]int, W+2)
				}
				q := make([][2]int, 0)
				q = append(q, [2]int{sx, sy})
				dist[sy][sx] = 0
				visited[sy][sx] = 1

				for len(q) > 0 {
					x, y := q[0][0], q[0][1]
					q = q[1:]

					if G[y][x+1] == '.' && visited[y][x+1] == -1 {
						q = append(q, [2]int{x + 1, y})
						dist[y][x+1] = dist[y][x] + 1
						visited[y][x+1] = 1
					}

					if G[y][x-1] == '.' && visited[y][x-1] == -1 {
						q = append(q, [2]int{x - 1, y})
						dist[y][x-1] = dist[y][x] + 1
						visited[y][x-1] = 1
					}

					if G[y+1][x] == '.' && visited[y+1][x] == -1 {
						q = append(q, [2]int{x, y + 1})
						dist[y+1][x] = dist[y][x] + 1
						visited[y+1][x] = 1
					}

					if G[y-1][x] == '.' && visited[y-1][x] == -1 {
						q = append(q, [2]int{x, y - 1})
						dist[y-1][x] = dist[y][x] + 1
						visited[y-1][x] = 1
					}
				}
				for i := 0; i < W+2; i++ {
					for j := 0; j < H+2; j++ {
						ans = max(ans, dist[j][i])
					}
				}
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
