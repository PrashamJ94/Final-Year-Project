package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	cutRibbon()
}

func cutRibbon() {
	var input string
	fmt.Scanln(&input)
	strArr := strings.Fields(input)
	arr := make([]int, len(strArr))
	for i, str := range strArr {
		num, _ := strconv.Atoi(str)
		arr[i] = num
	}
	length := arr[0]
	sort.Ints(arr[1:4])
	if length%arr[0] == 0 {
		fmt.Println(length / arr[0])
		return
	}
	ans := 0
	if arr[0] == arr[1] {
		k := 0
		for i := 0; i <= length/arr[2]; i++ {
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				k = check / arr[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		k := 0
		for i := 0; i <= length/arr[2]; i++ {
			for j := 0; j <= length/arr[1]; j++ {
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					k = check / arr[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// End of Code


Please note that Go does not have a built-in max function, so I added a simple max function at the end which returns the maximum of two integers.
