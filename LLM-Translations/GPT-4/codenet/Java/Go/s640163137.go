package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	a := make([]int, n)
	scanner.Scan()
	elements := strings.Split(scanner.Text(), " ")

	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(elements[i])
	}

	swapCount := 0

	for i := 0; i < len(a); i++ {
		mini := i

		for j := i; j < len(a); j++ {
			if a[j] < a[mini] {
				mini = j
			}
		}

		if mini != i {
			v := a[mini]
			a[mini] = a[i]
			a[i] = v

			swapCount++
		}
	}

	ans := fmt.Sprint(a[0])
	for i := 1; i < len(a); i++ {
		ans += " " + fmt.Sprint(a[i])
	}

	fmt.Println(ans)
	fmt.Println(swapCount)
}

// 
