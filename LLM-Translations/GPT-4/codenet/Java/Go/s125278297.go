package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	ans := make([]string, h)
	for i := 0; i < h; i++ {
		var s string
		fmt.Scan(&s)
		ans[i] = "#" + s + "#"
	}

	border := strings.Repeat("#", w+2)
	fmt.Println(border)
	for _, s := range ans {
		fmt.Println(s)
	}
	fmt.Println(border)

}
// 
