package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		m[a]++
	}
	ans := 0
	for _, v := range m {
		if v % 2 == 1 {
			ans++
		}
	}
	fmt.Println(ans)
}
// 
