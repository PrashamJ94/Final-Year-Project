package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var mod int64 = 1e9 + 7
var to [][]int
var dp []int

func main() {
	fs := NewFastScanner(os.Stdin)
	N := fs.NextInt()
	to = make([][]int, N)
	for i := 0; i < N; i++ {
		to[i] = make([]int, 0)
	}
	edges := make([][]int, N-1)
	for i := 0; i < N-1; i++ {
		A := fs.NextInt() - 1
		B := fs.NextInt() - 1
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges[i] = []int{B, A}
	}
	dp = make([]int, N)
	rec(0, -1)
	var mulsum int64 = 0
	for _, e := range edges {
		candidate1 := e[0]
		candidate2 := e[1]
		child := candidate1
		if dp[candidate1] > dp[candidate2] {
			child = candidate2
		}

		a := int64(dp[child])
		b := int64(N - a)

		mul := (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
		mulsum += mul
		mulsum %= mod
	}
	cases := modpow(2, int64(N))
	PN := (mulsum + (cases-1+mod)%mod) % mod

	BN := int64(N) * modpow(2, int64(N-1)) % mod
	WN := (PN - BN + mod) % mod
	ans := WN * modpow(cases, mod-2)
	ans %= mod

	fmt.Println(ans)
}

func rec(v int, parent int) int {
	res := 1
	for _, next := range to[v] {
		if next == parent {
			continue
		}
		res += rec(next, v)
	}
	dp[v] = res
	return res
}

func modpow(x int64, y int64) int64 {
	if y == 0 {
		return 1
	}
	if y%2 != 0 {
		return x * modpow(x, y-1) % mod
	}
	tmp := modpow(x, y/2)
	return tmp * tmp % mod
}

type FastScanner struct {
	reader    *bufio.Reader
	tokenizer *strings.Reader
}

func NewFastScanner(r io.Reader) *FastScanner {
	return &FastScanner{reader: bufio.NewReader(r)}
}

func (fs *FastScanner) Next() string {
	if fs.tokenizer == nil || fs.tokenizer.Len() == 0 {
		line, err := fs.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		fs.tokenizer = strings.NewReader(line)
	}
	var token strings.Builder
	for {
		r, _, err := fs.tokenizer.ReadRune()
		if err != nil || r == ' ' || r == '\n' {
			break
		}
		token.WriteRune(r)
	}
	return token.String()
}

func (fs *FastScanner) NextInt() int {
	n, _ := strconv.Atoi(fs.Next())
	return n
}

func (fs *FastScanner) NextLong() int64 {
	n, _ := strconv.ParseInt(fs.Next(), 10, 64)
	return n
}

func (fs *FastScanner) NextDouble() float64 {
	n, _ := strconv.ParseFloat(fs.Next(), 64)
	return n
}

func (fs *FastScanner) NextIntArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = fs.NextInt()
	}
	return a
}

func (fs *FastScanner) NextLongArray(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = fs.NextLong()
	}
	return a
}

// 
