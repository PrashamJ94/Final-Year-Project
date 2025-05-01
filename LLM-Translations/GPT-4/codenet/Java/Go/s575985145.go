package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var size int
	fmt.Scan(&size)
	graph := make([][]int, size)
	for i := 0; i < size; i++ {
		graph[i] = make([]int, size)
	}

	for i := 0; i < size; i++ {
		var id, cols int
		fmt.Scan(&id, &cols)
		row := make([]int, size)
		for j := 0; j < cols; j++ {
			var x int
			fmt.Scan(&x)
			row[x-1] = 1
		}
		graph[id-1] = row
	}

	for i := 0; i < len(graph); i++ {
		var rowStrings []string
		for j := 0; j < len(graph[i]); j++ {
			rowStrings = append(rowStrings, strconv.Itoa(graph[i][j]))
		}
		fmt.Println(strings.Join(rowStrings, " "))
	}
}

// 
