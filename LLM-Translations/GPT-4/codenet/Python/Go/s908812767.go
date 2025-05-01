
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var V = make(map[int][][]int)
var color = make(map[int]int)
var n int

func readInt() (int, error) {
	input, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	input = strings.TrimSpace(input)
	val, err := strconv.Atoi(input)
	if err != nil {
		return 0, err
	}
	return val, nil
}

func readInts() ([]int, error) {
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	input = strings.TrimSpace(input)
	split := strings.Split(input, " ")
	values := make([]int, len(split))
	for i, s := range split {
		val, err := strconv.Atoi(s)
		if err != nil {
			return nil, err
		}
		values[i] = val
	}
	return values, nil
}

func dfs(i int) bool {
	for _, vw := range V[i] {
		v := vw[0]
		w := vw[1]
		if w%2 == 0 {
			if color[v] == -1 {
				color[v] = color[i]
			} else if color[v] == color[i] {
				continue
			} else if color[v] != color[i] {
				return false
			}
		} else {
			if color[v] == -1 {
				color[v] = 0
				if color[i] != 0 {
					color[v] = 1
				}
			} else if color[v] == color[i] {
				return false
			} else if color[v] != color[i] {
				continue
			}
		}
		dfs(v)
	}
	return true
}

func main() {
	defer writer.Flush()
	var err error
	n, err = readInt()
	if err != nil {
		fmt.Println(err)
		return
	}

	for i := 1; i < n; i++ {
		uv, err := readInts()
		if err != nil {
			fmt.Println(err)
			return
		}
		u, v, w := uv[0], uv[1], uv[2]
		V[u] = append(V[u], []int{v, w})
		V[v] = append(V[v], []int{u, w})
	}

	for i := 1; i <= n; i++ {
		color[i] = -1
	}

	for {
		i := 0
		for j := 1; j <= n; j++ {
			if color[j] == -1 {
				i = j
				color[i] = 0
				break
			}
		}
		if i == 0 {
			for j := 1; j <= n; j++ {
				fmt.Println(color[j])
			}
			break
		} else {
			if !dfs(i) {
				fmt.Println("No")
				break
			}
		}
	}
}


