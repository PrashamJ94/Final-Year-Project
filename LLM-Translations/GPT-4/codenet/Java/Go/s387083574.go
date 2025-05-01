
package main

import (
	"fmt"
	"sort"
	"strconv"
)

type KeyValuePair struct {
	Key   int
	Value int
}

func main() {
	var N int
	fmt.Scan(&N)

	m := make(map[int]int)
	for i := 1; i < N+1; i++ {
		var value int
		fmt.Scan(&value)
		m[i] = value
	}

	sorted := sortMapByValue(m)
	for _, kvp := range sorted {
		fmt.Print(strconv.Itoa(kvp.Key) + " ")
	}
}

func sortMapByValue(m map[int]int) []KeyValuePair {
	var sorted []KeyValuePair
	for k, v := range m {
		sorted = append(sorted, KeyValuePair{k, v})
	}
	sort.Slice(sorted, func(i, j int) bool {
		return sorted[i].Value < sorted[j].Value
	})
	return sorted
}

// 
