package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	N, _ := strconv.ParseFloat(inputs[0], 64)
	d, _ := strconv.ParseFloat(inputs[1], 64)
	x, _ := strconv.ParseFloat(inputs[2], 64)
	
	fmt.Println(calc(N, d, x))
}

func calc(N float64, d float64, x float64) float64 {
	ret := 0.0
	for N > 0 {
		ret += d + (N - 0.5)*x
		d = d + (d/N) + (5*x)/(2*N)
		x += 2 * x / N
		N -= 1
	}
	return ret
}

// End of Code.
