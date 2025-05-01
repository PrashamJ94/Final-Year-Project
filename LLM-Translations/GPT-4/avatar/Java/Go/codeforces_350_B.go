Go
package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	for i := 1; i <= n; i++ {
		fmt.Scan(&b[i])
		num[b[i]]++
	}

	ss := ""
	ans := 0
	st := make([]bool, n+1)

	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			st[i] = true
			var sb strings.Builder
			x := b[i]
			var sss strings.Builder
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(" " + sss.String())
			s := 1

			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sss.Reset()
				sss.WriteString(strconv.Itoa(x))
				sb.WriteString(" " + sss.String())
				st[x] = true
				x = b[x]
				s++
			}

			if s > ans {
				ans = s
				ss = sb.String()
			}
		}
	}

	fmt.Println(ans)
	fmt.Println(ss)
}

// //End of Code


