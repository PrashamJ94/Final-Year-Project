


package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)
	s := make(map[string]int)
	l := make([]string, n)
	scanner := bufio.NewScanner(os.Stdin)
	f := "Yes"
	i := -1
	for j := 0; j < n; j++ {
		scanner.Scan()
		l[j] = scanner.Text()
	}
	for _, v := range l {
		s[v]++
		if s[v] >= 2 {
			f = "No"
		}
		if i != -1 && string(l[i][len(l[i])-1]) != string(v[0]) {
			f = "No"
		}
		i++
	}
	fmt.Println(f)
}
// End of Code


Please note that Go does not support the defaultdict construct from Python. Instead, Go's map type was used, which is an unordered collection of key-value pairs. Also, Go does not support the lambda construct from Python, so an explicit loop was used to iterate over the input values.
