
package main

import (
	"fmt"
	"strings"
	"strconv"
	"bufio"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	a := make([]int, n)
	for i, input := range inputs {
		a[i], _ = strconv.Atoi(input)
	}

	currentLevel := 0
	counter := 0
	counterTurns := -1

	for counter < len(a) {
		counterTurns++
		for i := 0; i < len(a); i++ {
			if a[i] != -1 && a[i] <= counter {
				counter++
				a[i] = -1
			}
		}
		for i := len(a)/2-1; i >= 0; i-- {
			opp := len(a)-1-i
			a[i], a[opp] = a[opp], a[i]
		}
	}
	fmt.Println(counterTurns)
}
// End of Code


