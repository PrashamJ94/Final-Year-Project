package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	sdic := make(map[string]int)

	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := strings.Split(scanner.Text(), "")
		sort.Strings(s)
		sortedS := strings.Join(s, "")
		if _, ok := sdic[sortedS]; ok {
			sdic[sortedS]++
		} else {
			sdic[sortedS] = 1
		}
	}

	ans := 0
	for _, v := range sdic {
		ans += v * (v - 1) / 2
	}
	fmt.Println(ans)
}

// 
