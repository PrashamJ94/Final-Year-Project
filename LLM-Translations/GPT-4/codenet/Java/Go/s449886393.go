package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	youbi := []string{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}
	ans := 0
	for i := 0; i < len(youbi); i++ {
		if strings.EqualFold(youbi[i], s) {
			ans = 7 - i
		}
	}
	fmt.Println(ans)
}
// 
