package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var N int
	var V []int
	var C []int
	fmt.Scan(&N)
	
	var tempV string
	fmt.Scan(&tempV)
	vString := strings.Split(tempV, " ")
	for _, value := range vString {
		intValue, _ := strconv.Atoi(value)
		V = append(V, intValue)
	}
	
	var tempC string
	fmt.Scan(&tempC)
	cString := strings.Split(tempC, " ")
	for _, value := range cString {
		intValue, _ := strconv.Atoi(value)
		C = append(C, intValue)
	}
	
	list := []int{0}
	var X, Y int
	for i := 0; i < N; i++ {
		if V[i] - C[i] > 0 {
			X = V[i]
			Y = C[i]
			list = append(list, X - Y)
		}
	}
	
	total := 0
	for _, value := range list {
		total += value
	}
	fmt.Println(total)
}

// End of Code
