
package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var N int
	var val string
	var total float32 = 0.0
	
	fmt.Scan(&N)
	
	for i := 0; i < N; i++ {
		fmt.Scan(&val)
		if strings.Contains(val, "JPY") {
			val = strings.Trim(val, "JPY")
			amount, _ := strconv.ParseFloat(val, 32)
			total += float32(amount)
		} else if strings.Contains(val, "BTC") {
			val = strings.Trim(val, "BTC")
			amount, _ := strconv.ParseFloat(val, 32)
			total += float32(amount) * 380000.0
		}
	}
	
	fmt.Println(total)
}
// End of Code


