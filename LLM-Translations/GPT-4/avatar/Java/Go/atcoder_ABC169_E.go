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
	var num int = 998244353
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	ai := make([]int, n)
	bi := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		s := strings.Split(scanner.Text(), " ")
		ai[i], _ = strconv.Atoi(s[0])
		bi[i], _ = strconv.Atoi(s[1])
	}

	sort.Ints(ai)
	sort.Ints(bi)

	if n%2 == 1 {
		fmt.Println(bi[n/2] - ai[n/2] + 1)
	} else {
		b := float64(ai[n/2]+ai[n/2-1]) / 2
		c := float64(bi[n/2]+bi[n/2-1]) / 2
		fmt.Println(int(2*(c-b) + 1))
	}
}

// //End of Code
