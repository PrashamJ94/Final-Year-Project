package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
)

var (
	reader *bufio.Reader
	writer *bufio.Writer
	mod    int64 = 1000000007
)

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}

func solve() {
	tmp := ns()
	s := []rune(tmp)
	n := len(s)
	ans := 0
	cnt := 0
	for i := 0; i < n; i++ {
		if s[i] == 'S' {
			cnt++
		} else {
			if cnt == 0 {
				continue
			}
			ans++
			cnt--
		}
	}
	fmt.Println(n - 2*ans)
}

func ns() string {
	buf := make([]byte, 0, 50)
	for {
		b, err := reader.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == ' ' || b == '\n' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

func ni() int {
	n, err := reader.ReadString(' ')
	if err != nil && err != io.EOF {
		panic(err)
	}
	num, err := strconv.Atoi(n[:len(n)-1])
	if err != nil {
		panic(err)
	}
	return num
}

func min(x, y int) int {
	return int(math.Min(float64(x), float64(y)))
}

func max(x, y int) int {
	return int(math.Max(float64(x), float64(y)))
}

func lowerBound(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool { return arr[i] >= x })
}

func upperBound(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool { return arr[i] > x })
}

func reverse(arr []int) {
	for i := 0; i < len(arr)/2; i++ {
		j := len(arr) - i - 1
		arr[i], arr[j] = arr[j], arr[i]
	}
}

// 
