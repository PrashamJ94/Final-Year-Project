
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	n          int
	a          []int
	dp         [][][]float64
	mod        int64 = 1e9 + 7
	inf        int   = 1<<31 - 1
	linf       int64 = 1<<63 - 1
	dinf       float64
	eps        float64 = 1e-10
	pi         float64 = math.Pi
	reader     *bufio.Reader
	writer     *bufio.Writer
	INPUT      string
	ptrbuf     int
	lenbuf     int
	inbuf      []byte
)

func main() {
	INPUT = ""
	reader = bufio.NewReaderSize(os.Stdin, 1<<20)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	solve()
}

func solve() {
	n = ni()
	a = na(n)
	dp = make([][][]float64, n+1)
	for i := range dp {
		dp[i] = make([][]float64, n+1)
		for j := range dp[i] {
			dp[i][j] = make([]float64, n+1)
			for k := range dp[i][j] {
				dp[i][j][k] = -1
			}
		}
	}
	cnt := make([]int, 3)
	for _, v := range a {
		cnt[v-1]++
	}
	ans := rec(cnt[0], cnt[1], cnt[2])
	fmt.Println(ans)
}

func rec(i, j, k int) float64 {
	if dp[i][j][k] != -1 {
		return dp[i][j][k]
	}
	ret := 0.0
	p := float64(i+j+k) / float64(n)
	pi := float64(i) / float64(n)
	pj := float64(j) / float64(n)
	pk := float64(k) / float64(n)
	ret += 1 / p
	if i > 0 {
		ret += pi / p * rec(i-1, j, k)
	}
	if j > 0 {
		ret += pj / p * rec(i+1, j-1, k)
	}
	if k > 0 {
		ret += pk / p * rec(i, j+1, k-1)
	}
	dp[i][j][k] = ret
	return ret
}

func readByte() byte {
	if ptrbuf >= lenbuf {
		ptrbuf = 0
		var err error
		lenbuf, err = reader.Read(inbuf)
		if err != nil {
			panic(err)
		}
		if lenbuf <= 0 {
			return 0
		}
	}
	ret := inbuf[ptrbuf]
	ptrbuf++
	return ret
}

func isSpaceChar(c byte) bool {
	return !(c >= 33 && c <= 126)
}

func skip() byte {
	b := readByte()
	for isSpaceChar(b) {
		b = readByte()
	}
	return b
}

func ni() int {
	n := 0
	isNegative := false
	b := readByte()
	for !(b >= '0' && b <= '9') || b == '-' {
		if b == '-' {
			isNegative = true
		}
		b = readByte()
	}
	for b >= '0' && b <= '9' {
		n = n*10 + int(b-'0')
		b = readByte()
	}
	if isNegative {
		return -n
	}
	return n
}

func na(n int) []int {
	a := make([]int, n)
	for i := range a {
		a[i] = ni()
	}
	return a
}


