
package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	NM := strings.Split(scanner.Text(), " ")

	N, _ := strconv.Atoi(NM[0])
	M, _ := strconv.Atoi(NM[1])

	scanner.Scan()
	Astr := strings.Split(scanner.Text(), " ")

	A := make([]int64, N)
	cum_remainders := make([]int64, N+1)
	remainder_counts := make(map[int64]int64)

	for i, v := range Astr {
		A[i], _ = strconv.ParseInt(v, 10, 64)
	}

	for i := 1; i <= N; i++ {
		cum_remainders[i] = (cum_remainders[i-1] + A[i-1]) % int64(M)
		remainder_counts[cum_remainders[i]]++
	}

	combinations := remainder_counts[0]
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}

	fmt.Println(combinations)
}
// End of Code

This Go code performs the same functionality as the original Python code. It reads input, performs calculations and prints out the result. The code uses bufio.NewScanner for reading input, strconv for parsing integers and strings, and make to initialize slices and maps. It also uses range for iterating over slices and maps.
