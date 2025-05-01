
package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2, temp string
	var i, j, t int

	fmt.Scanf("%s", &str1)
	fmt.Scanf("%s", &str2)

	i = len(str1)
	t = i - 1

	if len(str1) != len(str2) {
		fmt.Println("NO")
	} else {
		for j = 0; j < len(str1); j++ {
			temp = string(str1[t]) + temp
			t--
		}
		t = 0
		i = 0
		for i = 0; i < len(temp); i++ {
			if temp[i] == str2[i] {
				t++
			}
		}
		if len(str2) == t {
			fmt.Println("YES")
		} else if len(str2) != t {
			fmt.Println("NO")
		}
	}
}

// 


