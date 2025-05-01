package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, mx int
	fmt.Scan(&n)
	arr := make([]int, n)
	ans := make([]int, n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")

	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(inputs[i])
	}

	mx = arr[n-1]
	for i := n - 2; i >= 0; i-- {
		if mx - arr[i] + 1 > 0 {
			ans[i] = mx - arr[i] + 1
		}
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	for _, v := range ans {
		fmt.Print(v, " ")
	}
} 
//End of Code
