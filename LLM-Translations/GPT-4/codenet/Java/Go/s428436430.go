package main

import (
	"fmt"
)

type calArea struct{}

func (c *calArea) Area(w, h int) int {
	return w * h
}

func main() {
	var arr [4]int
	for i := 0; i < 4; i++ {
		fmt.Scan(&arr[i])
	}

	ab := &calArea{}
	area1 := ab.Area(arr[0], arr[1])
	area2 := ab.Area(arr[2], arr[3])

	if area1 > area2 {
		fmt.Println(area1)
	} else if area1 < area2 {
		fmt.Println(area2)
	} else if area1 == area2 {
		fmt.Println(area1)
	}

}

// 
