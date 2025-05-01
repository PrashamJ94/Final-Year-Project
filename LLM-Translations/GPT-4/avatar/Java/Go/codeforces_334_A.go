
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	square := n * n

	odd := make([]int, 0)
	even := make([]int, 0)

	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}

	loop := square / n
	div := loop / 2

	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Print(strconv.Itoa(odd[0]) + " " + strconv.Itoa(even[len(even)-1]) + " ")
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				fmt.Print(strconv.Itoa(even[0]) + " " + strconv.Itoa(odd[len(odd)-1]) + " ")
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Println()
	}
}
// //End of Code

The Go code above is the translated version of the provided Java code. It imports the necessary libraries and declares a main function. The main function takes an input number 'n', calculates the square of 'n', and creates two slices (i.e., resizable arrays in Go) for storing odd and even numbers up to 'square'. It then divides 'square' by 'n' to get a 'loop' variable and divides 'loop' by 2 to get a 'div' variable. The code then enters a nested loop where it prints out pairs of odd and even numbers based on the current iteration of the outer loop.
