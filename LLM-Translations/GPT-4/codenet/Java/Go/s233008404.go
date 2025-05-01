package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	colorMtr [][]string
	h        int
	w        int
	k        int
}

func main() {
	mainObj := &Main{}
	mainObj.solve()
}

func (m *Main) solve() {
	fs := NewFastScanner()

	m.h, _ = fs.nextInt()
	m.w, _ = fs.nextInt()
	m.k, _ = fs.nextInt()

	m.colorMtr = make([][]string, m.h)
	for i := 0; i < m.h; i++ {
		line, _ := fs.next()
		m.colorMtr[i] = strings.Split(line, "")
	}

	hPattern := pow(2, m.h)
	wPattern := pow(2, m.w)

	ans := 0

	for i := 0; i < hPattern; i++ {
		for j := 0; j < wPattern; j++ {
			if m.judge(i, j) {
				ans++
			}
		}
	}

	fmt.Println(ans)
}

func (m *Main) judge(hPattern, wPattern int) bool {

	hBitArr := make([]int, m.h)
	wBitArr := make([]int, m.w)

	for i := 0; i < m.h; i++ {
		if ((hPattern >> i) & 1) == 1 {
			hBitArr[i] = 1
		}
	}

	for i := 0; i < m.w; i++ {
		if ((wPattern >> i) & 1) == 1 {
			wBitArr[i] = 1
		}
	}

	black := 0

	for i := 0; i < m.h; i++ {
		for j := 0; j < m.w; j++ {
			if hBitArr[i] == 1 || wBitArr[j] == 1 {
				continue
			}

			if m.colorMtr[i][j] == "#" {
				black++
			}
		}
	}

	if black == m.k {
		return true
	} else {
		return false
	}
}

func pow(base, n int) int {
	retVal := 1
	for n > 0 {
		if (n & 1) == 1 {
			retVal *= base
		}
		n >>= 1
		base *= base
	}
	return retVal
}

type FastScanner struct {
	reader *bufio.Reader
	st     []string
}

func NewFastScanner() *FastScanner {
	return &FastScanner{
		reader: bufio.NewReader(os.Stdin),
	}
}

func (fs *FastScanner) next() (string, error) {
	if len(fs.st) == 0 {
		line, err := fs.reader.ReadString('\n')
		fs.st = strings.Fields(line)
		return fs.next()
	}
	nextWord := fs.st[0]
	fs.st = fs.st[1:]
	return nextWord, nil
}

func (fs *FastScanner) nextInt() (int, error) {
	s, err := fs.next()
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(s)
}

func (fs *FastScanner) nextLong() (int64, error) {
	s, err := fs.next()
	if err != nil {
		return 0, err
	}
	return strconv.ParseInt(s, 10, 64)
}

func (fs *FastScanner) nextIntArr(n int) ([]int, error) {
	retArr := make([]int, n)
	for i := 0; i < n; i++ {
		num, err := fs.nextInt()
		if err != nil {
			return nil, err
		}
		retArr[i] = num
	}
	return retArr, nil
}

func (fs *FastScanner) nextLongArr(n int) ([]int64, error) {
	retArr := make([]int64, n)
	for i := 0; i < n; i++ {
		num, err := fs.nextLong()
		if err != nil {
			return nil, err
		}
		retArr[i] = num
	}
	return retArr, nil
}

// 
