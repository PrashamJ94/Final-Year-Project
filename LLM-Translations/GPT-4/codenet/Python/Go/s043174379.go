package main

import (
	"fmt"
)

func main() {
	var H, W, h, w int
	fmt.Scan(&H, &W)
	fmt.Scan(&h, &w)

	ans := H*W - (h*W + w*H - h*w)
	fmt.Println(ans)
}

// 
