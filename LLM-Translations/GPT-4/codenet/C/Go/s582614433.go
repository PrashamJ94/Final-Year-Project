
package main

import (
	"fmt"
	"sort"
	"strconv"
)

type Edge struct {
	p int64
	i int64
	s string
}

type EdgeSlice []Edge

func (e EdgeSlice) Len() int {
	return len(e)
}

func (e EdgeSlice) Swap(i, j int) {
	e[i], e[j] = e[j], e[i]
}

func (e EdgeSlice) Less(i, j int) bool {
	if e[i].s != e[j].s {
		return e[i].s < e[j].s
	}
	return e[i].p > e[j].p
}

func main() {
	var n int64
	fmt.Scan(&n)

	data := make(EdgeSlice, n)

	for i := int64(0); i < n; i++ {
		var s string
		var p int64
		fmt.Scan(&s, &p)
		data[i] = Edge{p: p, i: i, s: s}
	}

	sort.Sort(data)

	for i := 0; i < len(data); i++ {
		fmt.Println(strconv.FormatInt(data[i].i+1, 10))
	}
}


