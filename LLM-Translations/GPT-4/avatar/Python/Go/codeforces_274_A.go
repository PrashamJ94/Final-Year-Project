
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var num, k int
	fmt.Scan(&num, &k)
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}
	different := map[int]bool{}
	temp := 0
	sort.Ints(arr)
	for _, x := range arr {
		if x%k != 0 || !different[x/k] {
			different[x] = true
		}
		if len(different) > temp {
			temp = len(different)
		}
	}
	fmt.Println(temp)
}
// End of Code

Please note that in Go, we don't have 'set' data structure. So, we use 'map' to mimic the 'set' behavior in Python. The 'map' data structure in Go provides the functionality of unordered collection of key-value pairs and it is widely used for efficient lookups, insertions, and deletions.
