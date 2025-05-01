package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n string
	fmt.Scan(&n)
	lastDigit, _ := strconv.Atoi(string(n[len(n)-1]))
	
	if lastDigit == 2 || lastDigit == 4 || lastDigit == 5 || lastDigit == 7 || lastDigit == 9 {
		fmt.Println("hon")
	} else if lastDigit == 0 || lastDigit == 1 || lastDigit == 6 || lastDigit == 8 {
		fmt.Println("pon")
	} else {
		fmt.Println("bon")
	}
}
// 
