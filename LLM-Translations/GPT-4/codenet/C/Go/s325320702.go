
package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

type fr struct {
	a, b int64
}

func swap(a, b *int64) {
	c := *b
	*b = *a
	*a = c
}

func min2(a, b int64) int64 {
	if a >= b {
		return b
	}
	return a
}

func max2(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}

func main() {
	var l, r, d, ans int64
	fmt.Scan(&l, &r, &d)

	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

// 

