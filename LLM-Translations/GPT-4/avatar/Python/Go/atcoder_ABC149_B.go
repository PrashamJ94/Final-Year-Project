
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	cookies := make([]int, 0, 3)
	for _, v := range strings.Split(input, " ") {
		if i, err := strconv.Atoi(v); err == nil {
			cookies = append(cookies, i)
		}
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := int(math.Max(0, float64(leftOver)))
	if takahashi > 0 {
		fmt.Println(strconv.Itoa(takahashi) + " " + strconv.Itoa(cookies[1]))
	} else {
		fmt.Println(strconv.Itoa(takahashi) + " " + strconv.Itoa(int(math.Max(0, float64(cookies[1]-math.Abs(float64(leftOver)))))))
	}
}
// End of Code

