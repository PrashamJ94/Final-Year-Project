package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var result []int
	scanner := bufio.NewScanner(os.Stdin)

	for {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		if n == 0 {
			break
		}

		scanner.Scan()
		line := scanner.Text()
		array2 := strings.Split(line, " ")
		input := make([]int, n)
		sum := 0

		for i := 0; i < n; i++ {
			input[i], _ = strconv.Atoi(array2[i])
			sum += input[i]
		}

		avg := float64(sum) / float64(n)
		num := 0

		for i := 0; i < n; i++ {
			if float64(input[i]) <= avg {
				num++
			}
		}

		result = append(result, num)
	}

	for i := 0; i < len(result); i++ {
		if result[i] == -1 {
			fmt.Println("NONE")
		} else {
			fmt.Println(result[i])
		}
	}
}

// 
