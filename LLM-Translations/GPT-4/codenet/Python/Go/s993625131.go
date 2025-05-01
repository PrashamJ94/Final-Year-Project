package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	count := 0
	record := 0
	for i := 0; i < len(S); i++ {
		if strings.Contains("ACGT", string(S[i])) {
			count++
		} else {
			if count > record {
				record = count
			}
			count = 0
		}
	}
	if count > record {
		record = count
	}

	fmt.Println(record)
}
// 
