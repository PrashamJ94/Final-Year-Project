package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var l string
	fmt.Scanln(&l)
	s := strings.Split(l, ".")
	p := s[1]
	i, _ := strconv.Atoi(string(p[0]))

	if s[0][len(s[0])-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if s[0][len(s[0])-1] != '9' && i < 5 {
		fmt.Println(s[0])
	} else {
		num, _ := strconv.Atoi(s[0])
		num++
		fmt.Println(strconv.Itoa(num))
	}
}

// End of Code
