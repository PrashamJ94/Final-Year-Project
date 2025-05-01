package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)

	s = strings.ReplaceAll(s, "BC", "D")

	cnt := int64(0)
	tmp := int64(0)

	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			tmp++
		} else if s[i] == 'D' {
			cnt += tmp
		} else {
			tmp = 0
		}
	}

	fmt.Fprintln(out, cnt)
}

// //End of Code.
