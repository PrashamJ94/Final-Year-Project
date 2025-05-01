
package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

const (
	INF  int64 = math.MaxInt64 / 2
	MOD  int64 = 1_000_000_007
	SIZE int   = 1_000_000
)

var (
	fac  [SIZE]int64
	inv  [SIZE]int64
	finv [SIZE]int64
	sc   = newFastScanner(os.Stdin)
)

func main() {
	solve()
}

func solve() {

	n := sc.nextInt()
	m := sc.nextInt()
	mp := make(map[int]int)

	for i := 0; i < m; i++ {
		s := sc.nextInt()
		c := sc.nextInt()
		if val, ok := mp[s]; ok && val != c {
			fmt.Println(-1)
			os.Exit(0)
		}
		mp[s] = c
	}

	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		flag := true
		if len(s) < n {
			continue
		}
		for j := 0; j < n; j++ {
			if val, ok := mp[j+1]; ok && val != int(s[j]-'0') || (!ok && int(s[j]-'0') != 0) {
				if !ok && j == 0 && int(s[j]-'0') == 1 {
					continue
				}
				flag = false
				break
			}
		}
		if flag && len(s) == n {
			fmt.Println(s)
			os.Exit(0)
		}
	}

	fmt.Println(-1)

}

type Pair struct {
	a, b int64
}

type Pairs []Pair

func (p Pairs) Len() int {
	return len(p)
}

func (p Pairs) Less(i, j int) bool {
	return p[i].b < p[j].b
}

func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

type FastScanner struct {
	reader *bufio.Reader
}

func newFastScanner(r io.Reader) *FastScanner {
	return &FastScanner{reader: bufio.NewReader(r)}
}

func (fs *FastScanner) hasNext() bool {
	for {
		r, _, err := fs.reader.ReadRune()
		if err != nil {
			return false
		}
		if isPrintableChar(r) {
			fs.reader.UnreadRune()
			return true
		}
	}
}

func (fs *FastScanner) next() string {
	var sb strings.Builder
	for {
		r, _, err := fs.reader.ReadRune()
		if err != nil || !isPrintableChar(r) {
			break
		}
		sb.WriteRune(r)
	}
	return sb.String()
}

func (fs *FastScanner) nextInt() int {
	return int(fs.nextLong())
}

func (fs *FastScanner) nextLong() int64 {
	n := int64(0)
	minus := false
	b := fs.readByte()
	if b == '-' {
		minus = true
		b = fs.readByte()
	}
	if b < '0' || '9' < b {
		panic("NumberFormatException")
	}
	for {
		if '0' <= b && b <= '9' {
			n = n*10 + int64(b-'0')
		} else if b == -1 || !isPrintableChar(rune(b)) {
			if minus {
				return -n
			}
			return n
		} else {
			panic("NumberFormatException")
		}
		b = fs.readByte()
	}
}

func (fs *FastScanner) nextDouble() float64 {
	f, _ := strconv.ParseFloat(fs.next(), 64)
	return f
}

func (fs *FastScanner) readByte() byte {
	b, err := fs.reader.ReadByte()
	if err != nil {
		return 0
	}
	return b
}

func isPrintableChar(r rune) bool {
	return 33 <= r && r <= 126
}


