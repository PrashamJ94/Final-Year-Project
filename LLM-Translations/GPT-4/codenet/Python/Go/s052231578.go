package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	arr := []int{111, 222, 333, 444, 555, 666, 777, 888, 999}
	ansIdx := sort.Search(len(arr), func(i int) bool { return arr[i] >= N })
	fmt.Println(arr[ansIdx])
}
// 
