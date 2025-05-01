Here is the equivalent Go code:


package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var a int
	fmt.Scanf("%d\n", &a)
	ar := make([]int, a)
	max := 0
	min := 0

	if scanner.Scan() {
		line := scanner.Text()
		nums := strings.Fields(line)
		for i := 0; i < len(nums); i++ {
			ar[i], _ = strconv.Atoi(nums[i])
		}
	}

	for i := 0; i < len(ar); i++ {
		max = int(math.Max(float64(ar[i]-ar[0]), float64(ar[len(ar)-1]-ar[i])))
		if i == 0 {
			min = ar[i+1] - ar[i]
		} else if i == len(ar)-1 {
			min = ar[i] - ar[i-1]
		} else {
			min = int(math.Min(float64(ar[i]-ar[i-1]), float64(ar[i+1]-ar[i])))
		}
		fmt.Println(min, max)
	}
}
// //End of Code

Please note that the Go version uses bufio.Scanner to read the input from the standard input, which is slightly different from how the Java version uses Scanner.
