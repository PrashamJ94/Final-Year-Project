package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewInputReader(inputStream)
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	solve(in, out)
}

func solve(sc *InputReader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		n := sc.NextInt64()
		m := sc.NextInt64()
		if n == 0 {
			fmt.Fprintln(pw, 0)
			continue
		}
		if n == m {
			fmt.Fprintln(pw, 0)
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			fmt.Fprintln(pw, Min(m-n, n))
			continue
		}
		fmt.Fprintln(pw, Min(m-n, n))
		t--
	}
}

func Min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReaderSize(stream, 32768)}
}

func (in *InputReader) Next() string {
	for {
		str, err := in.reader.ReadString(' ')
		if err == nil {
			return strings.TrimSpace(str)
		}
	}
}

func (in *InputReader) NextInt() int {
	val, _ := strconv.Atoi(in.Next())
	return val
}

func (in *InputReader) NextInt64() int64 {
	val, _ := strconv.ParseInt(in.Next(), 10, 64)
	return val
}

func (in *InputReader) NextDouble() float64 {
	val, _ := strconv.ParseFloat(in.Next(), 64)
	return val
}

// 
