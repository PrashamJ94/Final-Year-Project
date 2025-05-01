package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a int64
	var b string

	fmt.Scan(&a)
	fmt.Scan(&b)

	bString := strings.Replace(b, ".", "", -1)
	bInt, _ := strconv.Atoi(bString)
	bInt64 := int64(bInt)

	result := (a * bInt64) / 100

	fmt.Println(result)
}

// //End of Code
