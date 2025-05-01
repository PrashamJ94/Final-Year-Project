
package main

import (
	"fmt"
	"strings"
)

const patternBase = "keyence"

func strrstr(s, substr string) string {
	lastIndex := -1
	for {
		index := strings.Index(s, substr)
		if index == -1 {
			break
		}
		lastIndex = index
		s = s[index+1:]
	}
	if lastIndex == -1 {
		return ""
	}
	return s
}

func main() {
	var S string
	fmt.Scan(&S)

	found := false
	for offset := 0; offset < len(patternBase); offset++ {
		top := patternBase[:offset]
		bottom := patternBase[offset:]

		topSearch := strings.Index(S, top)
		if topSearch != -1 {
			bottomSearch := strings.LastIndex(S[topSearch+offset:], bottom)
			if bottomSearch != -1 {
				sepCount := 0

				if topSearch != 0 {
					sepCount++
				}
				if topSearch+offset != bottomSearch {
					sepCount++
				}
				if bottomSearch+len(bottom) != len(S) {
					sepCount++
				}

				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}


