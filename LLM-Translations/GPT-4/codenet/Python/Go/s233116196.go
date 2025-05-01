
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
	N, _ := strconv.Atoi(input[0])
	M, _ := strconv.Atoi(input[1])

	G := make(map[int][]int)
	for i := 1; i <= N; i++ {
		G[i] = []int{}
	}

	for i := 0; i < M; i++ {
		scanner.Scan()
		input := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(input[0])
		b, _ := strconv.Atoi(input[1])
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
	}

	col := make([]int, N+1)
	cnt := 0
	for i := 1; i <= N; i++ {
		if col[i] < 0 {
			col[i] = cnt
			que := []int{i}
			for len(que) > 0 {
				x := que[0]
				que = que[1:]
				for _, y := range G[x] {
					if col[y] < 0 {
						col[y] = cnt
						que = append(que, y)
					}
				}
			}
			cnt++
		}
	}

	cmax := -1
	for _, v := range col {
		if v > cmax {
			cmax = v
		}
	}
	fmt.Println(cmax)
}

// 


