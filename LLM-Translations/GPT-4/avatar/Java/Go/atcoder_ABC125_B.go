
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var vStr, cStr string
	fmt.Scanln(&vStr)
	fmt.Scanln(&cStr)

	vList := str2List(vStr)
	cList := str2List(cStr)

	max := 0
	for i := 0; i < n; i++ {
		profit := vList[i] - cList[i]
		if profit > 0 {
			max += profit
		}
	}
	fmt.Println(max)
}

func str2List(str string) map[int]int {
	vArrStr := strings.Split(str, " ")
	ret := make(map[int]int)
	key := 0
	for _, val := range vArrStr {
		j, _ := strconv.Atoi(val)
		ret[key] = j
		key++
	}
	return ret
}

// //End of Code

Please note that error handling has been omitted from the code for brevity. In a production environment, you would want to handle potential errors, such as failing to parse an integer.
