package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(testNumber int, in *InputReader, out *bufio.Writer) {
	n := in.nextInt()
	countArr := make([]int, n+1)
	for x := 1; x <= 100; x++ {
		for y := 1; y <= 100; y++ {
			for z := 1; z <= 100; z++ {
				value := x*x + y*y + z*z + x*y + x*z + y*z
				if value > n {
					break
				}
				countArr[value]++
			}
		}
	}

	for i := 1; i <= n; i++ {
		fmt.Fprintln(out, countArr[i])
	}
}

func main() {
	in := newInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	solve(1, in, out)
	out.Flush()
}

type InputReader struct {
	reader *bufio.Reader
}

func newInputReader(stream *os.File) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
	}
}

func (ir *InputReader) next() string {
	for {
		s, err := ir.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		s = strings.TrimSpace(s)
		if len(s) > 0 {
			return s
		}
	}
}

func (ir *InputReader) nextInt() int {
	i, err := strconv.Atoi(ir.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (ir *InputReader) nextLong() int64 {
	i, err := strconv.ParseInt(ir.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (ir *InputReader) nextDouble() float64 {
	f, err := strconv.ParseFloat(ir.next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

// 
