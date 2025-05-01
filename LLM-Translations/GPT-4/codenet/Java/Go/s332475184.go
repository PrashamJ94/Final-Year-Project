package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var counter []int
var graph [][]int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(input[0])
	q, _ := strconv.Atoi(input[1])

	graph = make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}

	counter = make([]int, n)
	var a, b int
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		input = strings.Split(scanner.Text(), " ")
		a, _ = strconv.Atoi(input[0])
		b, _ = strconv.Atoi(input[1])
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	for i := 0; i < q; i++ {
		scanner.Scan()
		input = strings.Split(scanner.Text(), " ")
		a, _ = strconv.Atoi(input[0])
		b, _ = strconv.Atoi(input[1])
		a--
		counter[a] += b
	}
	dfs(0, -1, 0)

	var result strings.Builder
	for i := 0; i < n; i++ {
		result.WriteString(strconv.Itoa(counter[i]))
		if i < n-1 {
			result.WriteString(" ")
		}
	}
	fmt.Println(result.String())
}

func dfs(v, par int, val int64) {
	for _, i := range graph[v] {
		if i != par {
			dfs(i, v, val+int64(counter[v]))
		}
	}
	counter[v] += int(val)
}
// 
