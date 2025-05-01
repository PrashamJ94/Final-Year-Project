
package main

import (
	"fmt"
	"sort"
)

func resolve() {
	var n int
	fmt.Scan(&n)
	low := make([]int, n)
	high := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&low[i], &high[i])
	}
	sort.Ints(low)
	sort.Ints(high)
	if n%2 != 0 {
		fmt.Println(high[(n+1)/2-1] - low[(n+1)/2-1] + 1)
	} else {
		hh := float64(high[n/2-1]+high[n/2]) / 2.0
		ll := float64(low[n/2-1]+low[n/2]) / 2.0
		fmt.Println(int((hh-ll)*2.0) + 1)
	}
}

func main() {
	resolve()
}

// End of Code

In Go, we need to import the required packages at the beginning of the code block. The fmt package is used for taking input and printing output, sort package is used for sorting the slice. Functions in Go are defined using the func keyword. Go doesn't not support implicit type conversion thus float64 is used to explicitly convert the integer to float for the division operation. The main function in Go is the entry point of the application. When the Go application starts, it will first run the main function.
