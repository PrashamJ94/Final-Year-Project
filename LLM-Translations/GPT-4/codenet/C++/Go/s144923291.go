
package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	target := "snuke"

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			var t string
			fmt.Scan(&t)
			if strings.Compare(target, t) == 0 {
				c := 'A' + j
				fmt.Printf("%c%d\n", c, i+1)
				return
			}
		}
	}
}


