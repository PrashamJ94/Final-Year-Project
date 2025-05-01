package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	N, _ := strconv.Atoi(input[0])
	x, _ := strconv.ParseInt(input[1], 10, 64)

	srimeList := make([]int64, N)
	scanner.Scan()
	input = strings.Split(scanner.Text(), " ")
	for i := 0; i < N; i++ {
		srimeList[i], _ = strconv.ParseInt(input[i], 10, 64)
	}

	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}

	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	result := make([]int64, N)
	for i := 0; i < N; i++ {
		sum := int64(0)
		for _, costArray := range costList {
			sum += costArray[i]
		}
		result[i] = int64(i) * x + sum
	}

	min := result[0]
	for _, val := range result {
		if val < min {
			min = val
		}
	}

	fmt.Println(min)
}

// //End of Code.
