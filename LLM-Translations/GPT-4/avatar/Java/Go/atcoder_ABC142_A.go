package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	inputFloat, _ := strconv.ParseFloat(input, 64)

	countOdd := math.Round(inputFloat / 2)
	result := big.NewRat(int64(countOdd), int64(inputFloat))
	fmt.Println(result.FloatString(10))
}

// //End of Code
