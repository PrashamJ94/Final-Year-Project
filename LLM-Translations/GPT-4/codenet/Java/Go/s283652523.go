package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

const MOD int64 = 1e9 + 7

func main() {
	in := NewFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	N := in.nextInt()
	A := in.nextIntArray(N)

	var ans, sum int64
	sum = int64(A[N-1])
	for i := N - 2; i >= 0; i-- {
		ans += (sum * int64(A[i])) % MOD
		ans %= MOD
		sum += int64(A[i])
		sum %= MOD
	}
	fmt.Fprintln(out, ans)
}

type FastScanner struct {
	reader *bufio.Reader
}

func NewFastScanner(r io.Reader) *FastScanner {
	return &FastScanner{reader: bufio.NewReader(r)}
}

func (fs *FastScanner) next() string {
	buf := make([]byte, 0)
	for {
		b, err := fs.reader.ReadByte()
		if err != nil {
			return ""
		}
		if b == ' ' || b == '\n' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

func (fs *FastScanner) nextInt() int {
	val, _ := strconv.Atoi(fs.next())
	return val
}

func (fs *FastScanner) nextInt64() int64 {
	val, _ := strconv.ParseInt(fs.next(), 10, 64)
	return val
}

func (fs *FastScanner) nextFloat64() float64 {
	val, _ := strconv.ParseFloat(fs.next(), 64)
	return val
}

func (fs *FastScanner) nextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = fs.nextInt()
	}
	return res
}

func (fs *FastScanner) nextInt64Array(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = fs.nextInt64()
	}
	return res
}

func (fs *FastScanner) nextFloat64Array(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = fs.nextFloat64()
	}
	return res
}

// 
