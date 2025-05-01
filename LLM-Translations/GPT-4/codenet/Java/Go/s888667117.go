package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	Si := scanner.Text()
	S := reverse(Si)

	var dp [13]int64
	dp[0] = 1

	d := 1
	for i := 0; i < len(S); i++ {
		var nd [13]int64
		c := S[i]

		if c >= '0' && c <= '9' {
			x := (int(c) - '0') * d

			for j := 0; j < 13; j++ {
				nd[(j+x)%13] = dp[j]
			}
		} else {
			for xi := 0; xi < 10; xi++ {
				x := xi * d

				for j := 0; j < 13; j++ {
					ni := (j + x) % 13
					nd[ni] = (nd[ni] + dp[j]) % 1000000007
				}
			}
		}

		dp = nd
		d = (d * 10) % 13
	}

	fmt.Println(dp[5])
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// 
