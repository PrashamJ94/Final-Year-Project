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
	nm := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(nm[0])
	m, _ := strconv.Atoi(nm[1])

	scanner.Scan()
	aStr := strings.Split(scanner.Text(), " ")
	a := make([]int, n)
	for i, val := range aStr {
		a[i], _ = strconv.Atoi(val)
	}
	sort.Ints(a)

	ope := make([][]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		opeStr := strings.Split(scanner.Text(), " ")
		ope[i] = make([]int, 2)
		ope[i][0], _ = strconv.Atoi(opeStr[0])
		ope[i][1], _ = strconv.Atoi(opeStr[1])
	}
	sort.Slice(ope, func(i, j int) bool {
		return ope[i][1] > ope[j][1]
	})

	j := 0
	for i := 0; i < n; i++ {
		if a[i] < ope[j][1] {
			a[i] = ope[j][1]
			ope[j][0] -= 1
			if ope[j][0] == 0 {
				j++
				if j == len(ope) {
					break
				}
			}
		} else {
			break
		}
	}
	sum := 0
	for _, val := range a {
		sum += val
	}
	fmt.Println(sum)
}

// 
