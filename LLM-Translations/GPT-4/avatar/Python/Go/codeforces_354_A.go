package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	elements := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(elements[0])
	L, _ := strconv.Atoi(elements[1])
	R, _ := strconv.Atoi(elements[2])
	QL, _ := strconv.Atoi(elements[3])
	QR, _ := strconv.Atoi(elements[4])

	scanner.Scan()
	w := strings.Split(scanner.Text(), " ")
	W := make([]int, n)
	sum_el := make([]int, n+1)
	for i := range W {
		W[i], _ = strconv.Atoi(w[i])
		if i > 0 {
			sum_el[i] = W[i-1] + sum_el[i-1]
		}
	}
	sum_el[n] = W[n-1] + sum_el[n-1]
	answer := QR*(n-1) + sum_el[n]*R
	for i := 1; i < n+1; i++ {
		energy := L*sum_el[i] + R*(sum_el[n] - sum_el[i])
		if i > (n - i) {
			energy = energy + (i - (n - i) - 1) * QL
		} else if (n - i) > i {
			energy = energy + ((n - i) - i - 1) * QR
		}
		if energy < answer {
			answer = energy
		}
	}
	fmt.Println(answer)
}
// End of Code.


Please note that Go handles input differently than Python, and as such, the Go code uses bufio and os packages to read from the standard input. The strconv package is used to convert strings read from the input to integers.
