
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func readInts() []int {
	line, _, _ := reader.ReadLine()
	strs := strings.Split(string(line), " ")
	ints := make([]int, len(strs))
	for i, str := range strs {
		ints[i], _ = strconv.Atoi(str)
	}
	return ints
}

func readGrid(h int) [][]int {
	grid := make([][]int, h)
	for i := 0; i < h; i++ {
		line, _, _ := reader.ReadLine()
		grid[i] = make([]int, len(line)-1)
		for j, ch := range line[:len(line)-1] {
			if ch == '#' {
				grid[i][j] = 1
			} else {
				grid[i][j] = 0
			}
		}
	}
	return grid
}

type node struct {
	cost int
	i    int
	j    int
}

func gridDijkstra(grid [][]int, si int, sj int) [][]int {
	h := len(grid)
	w := len(grid[0])
	d := make([][]int, h)
	for i := range d {
		d[i] = make([]int, w)
		for j := range d[i] {
			d[i][j] = -1
		}
	}

	que := make([]node, 0)
	que = append(que, node{0, si, sj})

	for len(que) > 0 {
		c, i, j := que[0].cost, que[0].i, que[0].j
		que = que[1:]
		if d[i][j] != -1 {
			continue
		}
		d[i][j] = c
		for di := -2; di <= 2; di++ {
			for dj := -2; dj <= 2; dj++ {
				ni, nj := i+di, j+dj
				if ni < 0 || ni >= h || nj < 0 || nj >= w || d[ni][nj] != -1 || grid[ni][nj] == 1 {
					continue
				}
				if (di == 0 && int(math.Abs(float64(dj))) == 1) || (dj == 0 && int(math.Abs(float64(di))) == 1) {
					que = append([]node{node{c, ni, nj}}, que...)
				} else {
					que = append(que, node{c + 1, ni, nj})
				}
			}
		}
	}

	return d
}

func main() {
	defer writer.Flush()

	params := readInts()
	h, w := params[0], params[1]

	s := readInts()
	si, sj := s[0]-1, s[1]-1

	t := readInts()
	ti, tj := t[0]-1, t[1]-1

	grid := readGrid(h)
	d := gridDijkstra(grid, si, sj)
	fmt.Fprintln(writer, d[ti][tj])
}


