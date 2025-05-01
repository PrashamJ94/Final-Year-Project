package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	i, k, p := 1, 0, 1
	flag := true
	a := make([]int, 1000)

	i = 0
	for k <= n {
		i += k
		if i >= n {
			for i >= n {
				i = i - n
			}
		}
		a[i]++
		k++
	}

	for i := 0; i < n; i++ {
		if a[i] == 0 {
			flag = false
			break
		}
	}

	if flag {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// //End of Code.
