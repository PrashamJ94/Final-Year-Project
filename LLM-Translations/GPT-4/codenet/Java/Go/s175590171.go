
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
	}
	sort.Ints(a)
	sum := 0
	count := 0
	for i := 0; i < n-1; i++ {
		sum += a[i]
		if a[i+1] <= 2*sum {
			count++
		} else {
			count = 0
		}
	}
	fmt.Println(count + 1)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}


