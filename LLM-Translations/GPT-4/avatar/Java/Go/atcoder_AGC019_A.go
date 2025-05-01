package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var Q, H, S, D, N float64

	Q, _ = strconv.ParseFloat(os.Args[1], 64)
	H, _ = strconv.ParseFloat(os.Args[2], 64)
	S, _ = strconv.ParseFloat(os.Args[3], 64)
	D, _ = strconv.ParseFloat(os.Args[4], 64)
	N, _ = strconv.ParseFloat(os.Args[5], 64)

	onePrice := math.Min(math.Min(Q*4, H*2), S)

	if onePrice <= D/2 {
		fmt.Println(N * onePrice)
	} else {
		fmt.Println((N/2)*D + math.Mod(N, 2)*onePrice)
	}
}

// //End of Code.
