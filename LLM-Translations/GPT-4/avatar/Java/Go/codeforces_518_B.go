package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	ura := 0
	opa := 0

	tmap := make(map[rune]int)
	for _, ch := range t {
		tmap[ch]++
	}

	srunes := []rune(s)
	length := len(srunes)
	for i := 0; i < length; i++ {
		ch := srunes[i]
		num, ok := tmap[ch]
		if !ok {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = num - 1
		}
		srunes[i] = 'Я'
		ura++
	}

	for i := 0; i < length; i++ {
		ch := srunes[i]
		rch := reverse(ch)
		num, ok := tmap[rch]
		if !ok {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch] = num - 1
		}
		opa++
	}

	fmt.Println(ura, opa)
}

func reverse(ch rune) rune {
	if unicode.IsLower(ch) {
		return unicode.ToUpper(ch)
	}
	return unicode.ToLower(ch)
}

// //End of Code.
