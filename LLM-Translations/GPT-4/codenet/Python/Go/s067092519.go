package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	m := make([][][]int, 10)
	for i := range m {
		m[i] = make([][]int, 3)
		for j := range m[i] {
			m[i][j] = make([]int, 10)
		}
	}

	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input)
		n := strings.Split(input, " ")
		b, _ := strconv.Atoi(n[0])
		f, _ := strconv.Atoi(n[1])
		r, _ := strconv.Atoi(n[2])
		v, _ := strconv.Atoi(n[3])
		m[b-1][f-1][r-1] += v
	}

	line := ""
	for i := 0; i < 4; i++ {
		for j := 0; j < 3; j++ {
			for k := 0; k < 10; k++ {
				line += fmt.Sprintf(" %d", m[i][j][k])
			}
			fmt.Println(line)
			line = ""
		}
		if i < 3 {
			fmt.Println(strings.Repeat("#", 20))
		}
	}
}

// 
