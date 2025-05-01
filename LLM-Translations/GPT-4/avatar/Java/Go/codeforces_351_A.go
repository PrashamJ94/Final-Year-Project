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
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(readLine(reader))
	inputStr := readLine(reader)
	inputs := strings.Split(inputStr, " ")

	arr := make([]float64, 2*n)
	nonInt := 0
	sumBefore := 0.0
	sum := 0.0

	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(inputs[i], 64)
		sumBefore += num
		if num != math.Floor(num) {
			nonInt++
		}
		sum += math.Floor(num)
		arr[i] = num
	}

	maxSum := math.Min(float64(n), float64(nonInt)) + sum
	minSum := math.Max(0, float64(nonInt-n)) + sum

	var ans float64
	if minSum > sumBefore {
		ans = minSum - sumBefore
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum
	} else {
		x := sumBefore - math.Floor(sumBefore)
		ans = math.Min(1-x, x)
	}

	fmt.Printf("%.3f", ans)
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

// //End of Code
