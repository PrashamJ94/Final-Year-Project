package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	g := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		g[i] = make([]int, n+1)
	}

	for i := 0; i < n; i++ {
		sc.Scan()
		info := strings.Split(sc.Text(), " ")
		u, _ := strconv.Atoi(info[0])
		k, _ := strconv.Atoi(info[1])
		for j := 0; j < k; j++ {
			v, _ := strconv.Atoi(info[j+2])
			g[u][v] = 1
		}
	}

	d := make([]int, n+1)
	for i := 0; i <= n; i++ {
		d[i] = -1
	}

	que := make([]int, 0)
	que = append(que, 1)
	d[1] = 0
	for len(que) > 0 {
		top := que[0]
		que = que[1:]
		for j := 1; j <= n; j++ {
			if g[top][j] == 1 && d[j] == -1 {
				que = append(que, j)
				d[j] = d[top] + 1
			}
		}
	}

	for i := 1; i <= n; i++ {
		fmt.Println(i, d[i])
	}
}

// 
