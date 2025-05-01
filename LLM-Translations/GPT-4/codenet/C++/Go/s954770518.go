
package main

import (
	"fmt"
	"sort"
)

func main() {
	s := make([]int, 10)
	for i := 0; i < 10; i++ {
		fmt.Scanf("%d", &s[i])
	}
	sort.Ints(s)
	for i := 9; i > 6; i-- {
		fmt.Printf("%d\n", s[i])
	}
}

// 


