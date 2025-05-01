package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

func main() {
	in := NewMyInput(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := NewSolver(in, out)
	solver.solve()
}

type Solver struct {
	in  *MyInput
	out *bufio.Writer
}

func NewSolver(in *MyInput, out *bufio.Writer) *Solver {
	return &Solver{in: in, out: out}
}

func (s *Solver) solve() {
	H := s.in.nextInt()
	W := s.in.nextInt()
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}
	for i := 0; i < H; i++ {
		c := s.in.nextString()
		for j, ch := range c {
			C[i+1][j+1] = ch
		}
	}
	if H == 1 && W == 1 {
		s.out.WriteString("No\n")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' &&
				C[i][j-1] != '#' && C[i][j+1] != '#' {
				s.out.WriteString("No\n")
				return
			}
		}
	}
	s.out.WriteString("Yes\n")
}

// ======================================================================
type MyInput struct {
	reader *bufio.Reader
}

func NewMyInput(reader io.Reader) *MyInput {
	return &MyInput{reader: bufio.NewReader(reader)}
}

func (
