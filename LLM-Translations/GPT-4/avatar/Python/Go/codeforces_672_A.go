
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var li []int
	for i := 1; i < 371; i++ {
		var temp []int
		p, q := i, i
		count := 0
		for p != 0 {
			p /= 10
			count++
		}
		if count == 1 {
			li = append(li, i)
		}
		if count == 2 || count == 3 {
			temp = nil
			for q != 0 {
				x := q % 10
				q /= 10
				temp = append([]int{x}, temp...)
			}
			li = append(li, temp...)
		}
	}
	li = li[:len(li)-2]
	var n int
	fmt.Scanf("%d", &n)
	fmt.Println(li[n-1])
}
// End of Code

The above Go code is a translation of your Python code. Please note that Go has different ways to handle user input and slicing arrays. For user input, instead of the input() function in Python, we use fmt.Scanf in Go. For slicing arrays, we need to specify both the start and end indices in Go, unlike Python, where we can omit the start index to slice from the beginning or the end index to slice to the end. So, li.pop() in Python is equivalent to li = li[:len(li)-1] in Go.
