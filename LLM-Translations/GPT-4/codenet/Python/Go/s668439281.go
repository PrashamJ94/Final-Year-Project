
package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	ls := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ls[i])
	}

	c := counter(ls)

	count := c.mostCommon()[0][1]
	ans := []string{}
	p := c.mostCommon()
	for i := 0; i < len(c); i++ {
		if p[i][1] == count {
			ans = append(ans, p[i][0])
		} else {
			break
		}
	}

	sort.Strings(ans)
	for _, i := range ans {
		fmt.Println(i)
	}
}

type counter map[string]int

func (c counter) mostCommon() [][2]interface{} {
	pairs := make([][2]interface{}, len(c))
	i := 0
	for key, value := range c {
		pairs[i] = [2]interface{}{key, value}
		i++
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i][1].(int) > pairs[j][1].(int)
	})
	return pairs
}

func counter(s []string) counter {
	m := make(map[string]int)
	for _, item := range s {
		_, ok := m[item]
		if !ok {
			m[item] = 1
		} else {
			m[item]++
		}
	}
	return m
}


// 
