
package main

import (
	"fmt"
	"sort"
)

func main() {
	var array [10]int
	for i := 0; i != 10; i++ {
		fmt.Scanf("%d", &array[i])
	}
	sort.Slice(array[:], func(i, j int) bool {
		return array[i] > array[j]
	})
	for i := 0; i != 3; i++ {
		fmt.Printf("%d\n", array[i])
	}
}
// 


