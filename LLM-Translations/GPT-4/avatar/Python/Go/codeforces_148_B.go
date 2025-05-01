package main

import (
	"fmt"
)

func main() {
	var princess, dragon, t, f, c int
	fmt.Scan(&princess)
	fmt.Scan(&dragon)
	fmt.Scan(&t)
	fmt.Scan(&f)
	fmt.Scan(&c)
	if dragon <= princess {
		fmt.Println(0)
		return
	}
	result := 0
	position := float64(t * princess)
	position += float64(princess) * position / float64(dragon-princess)
	for position < float64(c) {
		result++
		position += float64(princess) * position / float64(dragon)
		position += float64(princess * f)
		position += float64(princess) * position / float64(dragon-princess)
	}
	fmt.Println(result)
} 
// End of Code
