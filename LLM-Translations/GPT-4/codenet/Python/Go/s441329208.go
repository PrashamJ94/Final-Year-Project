
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')

	s = strings.TrimSpace(s)
	t = strings.TrimSpace(t)

	sSlice := strings.Split(s, "")
	tSlice := strings.Split(t, "")

	sort.Strings(sSlice)
	sort.Sort(sort.Reverse(sort.StringSlice(tSlice)))

	sSorted := strings.Join(sSlice, "")
	tSorted := strings.Join(tSlice, "")

	if sSorted < tSorted {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 


