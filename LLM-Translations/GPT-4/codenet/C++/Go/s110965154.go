
package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func insertionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		if i != 0 {
			intValue := arr[i]
			j := i - 1
			for j >= 0 && arr[j] > intValue {
				arr[j+1] = arr[j]
				j--
			}
			arr[j+1] = intValue
		}

		for k := 0; k < len(arr); k++ {
			fmt.Print(arr[k])
			if k != len(arr)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	var num int
	fmt.Scan(&num)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	values := make([]int, num)

	for i, v := range input {
		values[i], _ = strconv.Atoi(v)
	}

	insertionSort(values)
}

// 
