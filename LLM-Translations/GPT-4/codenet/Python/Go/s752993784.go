package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	s := []rune(input)
	mods := make([]int, len(s))
	countRemainder := make([]int, 2019)
	cnt := 0

	m := 1
	mod := 0
	for i := range s {
		num, _ := strconv.Atoi(string(s[len(s)-i-1]))
		mod += num * m

		mod %= 2019
		m *= 10
		m %= 2019

		countRemainder[mod]++
	}

	countRemainder[0]++

	for i := 0; i < 2019; i++ {
		cnt += int(countRemainder[i] * (countRemainder[i] - 1) / 2)
	}

	fmt.Println(cnt)
}

// 
