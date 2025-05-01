package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var w, n int
	fmt.Scan(&w, &n)
	values := make([]int, w)
	for i := range values {
		values[i] = i + 1
	}
	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		ab := strings.Split(str, ",")
		a, _ := strconv.Atoi(ab[0])
		b, _ := strconv.Atoi(ab[1])
		a--
		b--
		values[a], values[b] = values[b], values[a]
	}
	for _, value := range values {
		fmt.Println(value)
	}
}
// 
