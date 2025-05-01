package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Pair struct {
	x int
	y int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	arrStr := strings.Split(scanner.Text(), " ")
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(arrStr[i])
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i] > arr[j] })

	var ans int64
	if n >= 3 {
		pairMap := map[Pair]int{}
		ans = int64(arr[0] + arr[1])
		pairMap[Pair{arr[0], arr[1]}] = 1
		p1, p2 := Pair{arr[2], arr[1]}, Pair{arr[2], arr[0]}
		put(pairMap, p1)
		put(pairMap, p2)

		for i := 3; i < n; i++ {
			p := getMaxPair(pairMap)
			rem(pairMap, p)
			ans += int64(min(p.x, p.y))
			put(pairMap, Pair{p.x, arr[i]})
			put(pairMap, Pair{p.y, arr[i]})
		}
		fmt.Println(ans)
	} else {
		fmt.Println(arr[0])
	}
}

func put(pairMap map[Pair]int, p Pair) {
	if _, ok := pairMap[p]; ok {
		pairMap[p]++
	} else {
		pairMap[p] = 1
	}
}

func rem(pairMap map[Pair]int, p Pair) {
	if pairMap[p] == 1 {
		delete(pairMap, p)
	} else {
		pairMap[p]--
	}
}

func getMaxPair(pairMap map[Pair]int) Pair {
	maxPair := Pair{0, 0}
	for p := range pairMap {
		if p.x > maxPair.x || (p.x == maxPair.x && p.y > maxPair.y) {
			maxPair = p
		}
	}
	return maxPair
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// 
