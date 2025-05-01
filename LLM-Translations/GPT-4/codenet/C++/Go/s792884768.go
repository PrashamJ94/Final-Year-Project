
package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
	"strings"
)

type TSize struct {
	r int
	c int
}

func NewTSize(r, c int) TSize {
	return TSize{r: r, c: c}
}

type TMcmSolver struct {
	FMemo  [][]int
	FChain []TSize
}

func Count(Left, Right TSize) int {
	return Left.r * Right.c * Left.c
}

func (solver *TMcmSolver) Solve(s, l int) int {
	if s == l {
		return 0
	}
	if solver.FMemo[s][l] != 0 {
		return solver.FMemo[s][l]
	}
	if s+1 == l {
		solver.FMemo[s][l] = Count(solver.FChain[s], solver.FChain[l])
	} else {
		min := math.MaxInt32
		for i := s; i < l; i++ {
			c := solver.Solve(s, i) + Count(TSize{solver.FChain[s].r, solver.FChain[i].c}, TSize{solver.FChain[i+1].r, solver.FChain[l].c}) + solver.Solve(i+1, l)
			if c < min {
				min = c
			}
		}
		solver.FMemo[s][l] = min
	}
	return solver.FMemo[s][l]
}

func NewTMcmSolver(Chain []TSize) TMcmSolver {
	FMemo := make([][]int, len(Chain))
	for i := range FMemo {
		FMemo[i] = make([]int, len(Chain))
	}
	return TMcmSolver{FMemo: FMemo, FChain: Chain}
}

func (solver *TMcmSolver) Answer() int {
	return solver.Solve(0, len(solver.FMemo)-1)
}

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println(0)
		return
	}
	Chain := make([]TSize, n)

	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		r, _ := strconv.Atoi(parts[0])
		c, _ := strconv.Atoi(parts[1])
		Chain[i] = NewTSize(r, c)
	}

	Solver := NewTMcmSolver(Chain)

	fmt.Println(Solver.Answer())
}

// 
