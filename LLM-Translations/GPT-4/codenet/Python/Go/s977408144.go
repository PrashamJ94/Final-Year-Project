
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
	nl := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(nl[0])
	l, _ := strconv.Atoi(nl[1])

	S := make([]string, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		S[i] = scanner.Text()
	}

	sort.Strings(S)
	fmt.Println(strings.Join(S, ""))
}
// 

