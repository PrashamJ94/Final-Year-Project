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
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	aLine := sc.Text()
	aSlice := strings.Fields(aLine)
	aLi := make([]int, N)
	for i, aStr := range aSlice {
		aLi[i], _ = strconv.Atoi(aStr)
	}

	sort.Ints(aLi)

	n := aLi[N-1]

	dif := int(1e18)
	prevDif := dif
	var r int
	for _, a := range aLi[:N-1] {
		curDif := abs(n/2 - a)
		if curDif < dif {
			dif = curDif
			r = a
			prevDif = dif
		}
	}

	fmt.Println(n, r)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 
