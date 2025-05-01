package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var str1, str2 string
	fmt.Scanln(&str1, &str2)

	str1Sorted := strings.Split(str1, "")
	str2Sorted := strings.Split(str2, "")

	sort.Strings(str1Sorted)
	sort.Sort(sort.Reverse(sort.StringSlice(str2Sorted)))

	loop := len(str1Sorted)
	if len(str2Sorted) < loop {
		loop = len(str2Sorted)
	}

	flag := false

	for i := 0; i < loop; i++ {
		ch1 := str1Sorted[i]
		ch2 := str2Sorted[i]

		if ch1 == ch2 {
			if loop == i+1 && len(str1Sorted) < len(str2Sorted) {
				flag = true
				break
			} else {
				continue
			}
		} else {
			if ch2 > ch1 {
				flag = true
				break
			} else {
				break
			}
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
