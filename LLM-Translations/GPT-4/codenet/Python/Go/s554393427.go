package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)
	mo := make([][]interface{}, N)
	for i := 0; i < N; i++ {
		var x float64
		var u string
		fmt.Scan(&x, &u)
		mo[i] = []interface{}{x, u}
	}
	okz := 0.0
	for _, i := range mo {
		if i[1] == "JPY" {
			okz += i[0].(float64)
		} else {
			okz += i[0].(float64) * 380000
		}
	}
	fmt.Println(strconv.FormatFloat(okz, 'f', -1, 64))
}

// 
