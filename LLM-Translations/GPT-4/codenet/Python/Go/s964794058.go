package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var memTime int
	fmt.Scan(&memTime)

	var memLateInput string
	fmt.Scan(&memLateInput)

	memLateStr := strings.Split(memLateInput, " ")
	memLate := make([]int, len(memLateStr))
	for i, s := range memLateStr {
		memLate[i], _ = strconv.Atoi(s)
	}

	colorList := make(map[int]bool)
	memColor := 0
	highLate := 0

	for color := 0; color < memTime; color++ {
		member := memLate[color]
		if member/400 >= 8 {
			highLate++
		} else if !colorList[member/400] {
			colorList[member/400] = true
		}
	}
	maxColor := len(colorList) + highLate
	minColor := len(colorList)
	if minColor == 0 {
		minColor = 1
	}
	fmt.Printf("%d %d\n", minColor, maxColor)
}

// 
