package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	lst := make([]string, 0)
	pair := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		st := strings.Split(scanner.Text(), "")
		sort.Strings(st)
		sortedSt := strings.Join(st, "")
		lst = append(lst, sortedSt)
	}
	sort.Strings(lst)
	lst = append(lst, "end")
	pre := ""
	tmpCnt := 0
	cnt := 0
	for _, i := range lst {
		if i == pre {
			tmpCnt++
		} else {
			cnt += sum(tmpCnt + 1)
			tmpCnt = 0
		}
		pre = i
	}
	fmt.Println(cnt)
}

func sum(n int) int {
	return (n * (n - 1)) / 2
}

// 
