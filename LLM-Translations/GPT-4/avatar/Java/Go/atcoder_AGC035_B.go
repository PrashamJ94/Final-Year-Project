
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	connect [][]int
	visited []int
	odd     []bool
	print   []string
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	numNode, _ := strconv.Atoi(input[0])
	numEdge, _ := strconv.Atoi(input[1])

	connect = make([][]int, numNode)
	for i := range connect {
		connect[i] = make([]int, 0)
	}

	for i := 0; i < numEdge; i++ {
		scanner.Scan()
		edge := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(edge[0])
		a--
		b, _ := strconv.Atoi(edge[1])
		b--
		connect[a] = append(connect[a], b)
		connect[b] = append(connect[b], a)
	}

	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}

	visited = make([]int, numNode)
	odd = make([]bool, numNode)
	print = make([]string, 0)

	dfs(0, -1)

	for _, val := range print {
		fmt.Println(val)
	}
}

func dfs(crt, parent int) {
	visited[crt] = 1
	crtConnect := connect[crt]
	for _, child := range crtConnect {
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			print = append(print, fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] = !odd[crt]
		} else {
			dfs(child, crt)
			if odd[child] {
				print = append(print, fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] = !odd[child]
			} else {
				print = append(print, fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] = !odd[crt]
			}
		}
	}
	visited[crt] = 2
}

// //End of Code
