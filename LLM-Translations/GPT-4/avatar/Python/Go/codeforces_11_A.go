package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, d int
	fmt.Scan(&n, &d)

	var x []int
	var m, q int
	str, _ := reader.ReadString('\n')
	str = strings.Replace(str, "\n", "", -1)
	strArr := strings.Split(str, " ")

	for i := 0; i < len(strArr); i++ {
		num, _ := strconv.Atoi(strArr[i])
		x = append(x, num)
	}

	for a := 0; a < len(x) - 1; a++ {
		if x[a] >= x[a+1] {
			q = (x[a] - x[a+1]) / d + 1
			m = m + q
			x[a+1] = x[a+1] + q * d
		}
	}

	fmt.Println(m)
}
// End of Code

This code reads in two integers n and d, a line of integers as elements of an array x, and then performs the operations as described in your Python code. The result m is then printed out. The Go code uses the bufio package for reading the input, the strings package for string manipulation and the strconv package for converting string to integer.

Please note that error handling for the input reading and conversion is minimal for simplicity. In a production environment, you would want to handle potential errors more robustly. 
