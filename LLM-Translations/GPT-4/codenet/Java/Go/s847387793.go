package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type Solver struct {
	sc     *bufio.Scanner
	writer *bufio.Writer

	n, m, q int
	max     int
	a, b, c, d []int
}

func NewSolver(sc *bufio.Scanner, writer *bufio.Writer) *Solver {
	return &Solver{
		sc:     sc,
		writer: writer,
	}
}

func (s *Solver) run() {
	s.n, _ = strconv.Atoi(s.next())
	s.m, _ = strconv.Atoi(s.next())
	s.q, _ = strconv.Atoi(s.next())
	s.a = make([]int, s.q)
	s.b = make([]int, s.q)
	s.c = make([]int, s.q)
	s.d = make([]int, s.q)
	for i := 0; i < s.q; i++ {
		s.a[i], _ = strconv.Atoi(s.next())
		s.b[i], _ = strconv.Atoi(s.next())
		s.c[i], _ = strconv.Atoi(s.next())
		s.d[i], _ = strconv.Atoi(s.next())
	}
	s.dfs([]int{1})
	s.writer.WriteString(fmt.Sprintf("%d\n", s.max))
}

func (s *Solver) dfs(array []int) {
	if len(array) > s.n {
		score := 0
		for i := 0; i < s.q; i++ {
			if array[s.b[i]]-array[s.a[i]] == s.c[i] {
				score += s.d[i]
			}
		}
		s.max = max(s.max, score)
		return
	}

	newArray := make([]int, len(array)+1)
	copy(newArray, array)
	newArray[len(array)] = array[len(array)-1]

	for newArray[len(newArray)-1] <= s.m {
		s.dfs(newArray)
		newArray[len(newArray)-1]++
	}
}

func (s *Solver) next() string {
	s.sc.Scan()
	return s.sc.Text()
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solver := NewSolver(sc, writer)
	solver.run()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
