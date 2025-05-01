
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
	reader := NewInputReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := reader.NextInt()
	m := reader.NextInt()
	a := reader.NextIntArray(n)

	dp := make(map[int]int)
	var ans int64 = 0
	var base int = 0

	for i := 0; i < n; i++ {
		base = (base - a[i]%m + m) % m
		dp[(base+a[i])%m]++
		ans += int64(dp[base])
	}
	fmt.Fprintln(writer, ans)
}

type InputReader struct {
	br *bufio.Reader
	st *strings.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{br: bufio.NewReader(r), st: &strings.Reader{}}
}

func (ir *InputReader) nextLine() string {
	line, err := ir.br.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(line)
}

func (ir *InputReader) nextToken() string {
	for ir.st.Len() == 0 {
		ir.st = strings.NewReader(ir.nextLine())
	}
	var token string
	_, err := fmt.Fscan(ir.st, &token)
	if err != nil {
		panic(err)
	}
	return token
}

func (ir *InputReader) NextInt() int {
	n, err := strconv.Atoi(ir.nextToken())
	if err != nil {
		panic(err)
	}
	return n
}

func (ir *InputReader) NextIntArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = ir.NextInt()
	}
	return res
}

// //End of Code.
