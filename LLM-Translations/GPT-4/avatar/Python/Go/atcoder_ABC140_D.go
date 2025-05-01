package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
)

func next() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	v, _ := strconv.Atoi(next())
	return v
}

func main() {
	scanner.Split(bufio.ScanWords)
	MOD := int(1e9 + 7)
	N := nextInt()
	K := nextInt()
	S := next()
	seg_cnt := 0
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			seg_cnt++
		}
	}
	cur_happy := N - 1 - seg_cnt
	var ans int
	if 2*K >= seg_cnt {
		ans = N - 1
	} else {
		ans = cur_happy + 2*K
	}
	fmt.Println(ans)
}
// End of Code.
