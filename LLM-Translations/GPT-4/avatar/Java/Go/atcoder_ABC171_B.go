package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	inputs := readInts(in)
	n, k := inputs[0], inputs[1]
	a := readInts(in)

	sort.Ints(a)
	ans := 0

	for i := 0; i < k; i++ {
		ans += a[i]
	}

	fmt.Fprintln(out, ans)
}

func readInts(in *bufio.Reader) []int {
	line, _ := in.ReadString('\n')
	parts := strings.Fields(line)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// //End of Code.
