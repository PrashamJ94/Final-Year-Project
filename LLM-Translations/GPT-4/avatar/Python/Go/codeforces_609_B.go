
package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(inputs[0])
	m, _ := strconv.Atoi(inputs[1])

	scanner.Scan()
	inputs = strings.Split(scanner.Text(), " ")
	lst := make([]int, n)
	for i, str := range inputs {
		lst[i], _ = strconv.Atoi(str)
	}

	l := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := l[lst[i]]; !ok {
			l[lst[i]] = 1
		} else {
			l[lst[i]]++
		}
	}

	res := 0
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			res += n - i - l[lst[i]]
			l[lst[i]]--
		} else {
			res += n - i - 1
		}
	}

	fmt.Println(res)
}
// End of Code


