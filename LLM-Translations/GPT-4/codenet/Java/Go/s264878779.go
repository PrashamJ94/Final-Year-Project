package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	n := len(s)
	var ans int64
	for mask := 0; mask < 1<<(n-1); mask++ {
		var sum int64
		x := string(s[0])
		for i := 0; i < n-1; i++ {
			if (mask & (1 << i)) >= 1 {
				x += "+" + string(s[i+1])
			} else {
				x += string(s[i+1])
			}
		}
		split := strings.Split(x, "+")
		for i := 0; i < len(split); i++ {
			num, _ := strconv.ParseInt(split[i], 10, 64)
			sum += num
		}
		ans += sum
	}
	fmt.Println(ans)
}

// 
