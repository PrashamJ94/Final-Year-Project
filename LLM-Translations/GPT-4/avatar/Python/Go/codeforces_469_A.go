package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var max_level int
	fmt.Scan(&max_level)
	
	var temp string
	fmt.Scan(&temp)
	x := strings.Split(temp, " ")
	x = x[1:]
	
	fmt.Scan(&temp)
	y := strings.Split(temp, " ")
	y = y[1:]
	
	xSet := make(map[int]struct{})
	ySet := make(map[int]struct{})
	
	for _, val := range x {
		intVal, _ := strconv.Atoi(val)
		if intVal != 0 {
			xSet[intVal] = struct{}{}
		}
	}
	
	for _, val := range y {
		intVal, _ := strconv.Atoi(val)
		if intVal != 0 {
			ySet[intVal] = struct{}{}
		}
	}
	
	z := make(map[int]struct{})
	for key := range xSet {
		z[key] = struct{}{}
	}
	for key := range ySet {
		z[key] = struct{}{}
	}
	
	if len(z) != max_level {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}

// End of Code
