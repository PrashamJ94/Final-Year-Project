package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	input := NewMyInput(os.Stdin)
	K := input.NextInt()
	S := input.NextInt()

	ans := 0
	var wk int
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			wk = S - x - y
			if wk >= 0 && wk <= K {
				ans++
			}
		}
	}
	fmt.Println(ans)
}

type MyInput struct {
	in *bufio.Reader
}

func NewMyInput(r io.Reader) *MyInput {
	return &MyInput{
		in: bufio.NewReader(r),
	}
}

func (mi *MyInput) NextInt() int {
	i, _ := strconv.Atoi(mi.NextString())
	return i
}

func (mi *MyInput) NextLong() int64 {
	i, _ := strconv.ParseInt(mi.NextString(), 10, 64)
	return i
}

func (mi *MyInput) NextString() string {
	s, _ := mi.in.ReadString(' ')
	return s
}

func (mi *MyInput) NextDChar() string {
	s, _ := mi.in.ReadString('\n')
	return s
}

// 
