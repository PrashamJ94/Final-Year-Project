package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	f := 0
	a := make([]int, n)
	sc.Scan()
	input := strings.Split(sc.Text(), " ")

	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(input[i])
	}
	var k, j, i int
	for k = 0; k < n; k++ {
		t := a[k]
		for i = 0; i < n; i++ {
			for j = 0; j < n-1; j++ {
				if i != j && t == (a[i]+a[j]) {
					f = 1
					break
				}
			}
			if f == 1 {
				break
			}
		}
		if f == 1 {
			break
		}
	}
	if f == 1 {
		fmt.Println(k+1, j+1, i+1)
	} else {
		fmt.Println("-1")
	}
}

// //End of Code.
