package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	sc := newScanner()
	H := sc.nextInt()
	W := sc.nextInt()
	c := make([][]int, 10)
	for i := 0; i < 10; i++ {
		c[i] = make([]int, 10)
		for j := 0; j < 10; j++ {
			c[i][j] = sc.nextInt()
		}
	}
	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}
	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				min[i] = int(math.Min(float64(min[i]), float64(c[i][j]+min[j])))
			}
		}
	}
	ans := 0
	for h := 1; h <= H; h++ {
		for w := 1; w <= W; w++ {
			A := sc.nextInt()
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	fmt.Println(ans)
}

type scanner struct {
	reader *bufio.Reader
}

func newScanner() *scanner {
	return &scanner{reader: bufio.NewReader(os.Stdin)}
}

func (s *scanner) next() string {
	str, err := s.reader.ReadString(' ')
	if err != nil {
		panic(err)
	}
	return str[:len(str)-1]
}

func (s *scanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *scanner) nextLong() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (s *scanner) nextFloat() float64 {
	f, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

// 
