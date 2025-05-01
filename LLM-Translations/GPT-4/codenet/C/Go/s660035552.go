package main

import (
	"fmt"
	"sort"
)

type interval struct {
	start int
	end   int
}

type intervalSlice []interval

func (p intervalSlice) Len() int           { return len(p) }
func (p intervalSlice) Less(i, j int) bool { return p[i].end < p[j].end }
func (p intervalSlice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	intervals := make(intervalSlice, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&intervals[i].start, &intervals[i].end)
	}

	sort.Sort(intervals)

	cnt := 0
	t := 0
	for i := 0; i < m; i++ {
		if t <= intervals[i].start {
			t = intervals[i].end
			cnt++
		}
	}

	fmt.Println(cnt)
}

// 
