package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	cnt := make([]int, 26)
	for i := range cnt {
		cnt[i] = 1
	}
	s := make([]rune, n)
	for i := range s {
		fmt.Scan(&s[i])
		cnt[s[i]-'a']++
	}

	ans := int64(cnt[0])
	mod := int64(math.Pow10(9) + 7)
	for i := 1; i < 26; i++ {
		ans *= int64(cnt[i])
		ans %= mod
	}

	fmt.Println(ans - 1)
}
// 
