package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(str[0])
	d, _ := strconv.Atoi(str[1])
	cnt := 0

	for i := 0; i < n; i++ {
		scanner.Scan()
		str = strings.Split(scanner.Text(), " ")
		x, _ := strconv.Atoi(str[0])
		y, _ := strconv.Atoi(str[1])
		if math.Sqrt(float64(x*x+y*y)) <= float64(d) {
			cnt++
		}
	}
	fmt.Println(cnt)
}

// 
