
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type codeforces_216_B struct {
	count int
	seen  []bool
	graph [][]int
}

func (ft *codeforces_216_B) dfs(child int, par int) bool {
	if ft.seen[child] {
		return true
	}
	ft.seen[child] = true

	for _, i := range ft.graph[child] {
		if i != par {
			ft.count++
			if ft.dfs(i, child) {
				return true
			}
		}
	}
	return false
}

func main() {
	sc := bufio.NewScanner(bufio.NewReader(os.Stdin))
	sc.Split(bufio.ScanWords)
	sc.Scan()
	m, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	ft := &codeforces_216_B{}
	ft.graph = make([][]int, m+1)
	ft.seen = make([]bool, m+1)

	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ := strconv.Atoi(sc.Text())
		ft.graph[x] = append(ft.graph[x], y)
		ft.graph[y] = append(ft.graph[y], x)
	}

	toremove := 0
	for i := 1; i <= m; i++ {
		if !ft.seen[i] {
			ft.count = 0
			if ft.dfs(i, 0) {
				if ft.count%2 == 1 {
					toremove++
				}
			}
		}
	}

	if (m-toremove)%2 == 1 {
		toremove++
	}
	fmt.Println(toremove)
}
// //End of Code


