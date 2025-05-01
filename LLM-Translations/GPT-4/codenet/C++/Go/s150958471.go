package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	var train [2]int
	var bus [2]int

	reader := bufio.NewReader(os.Stdin)

	inputTrain, _ := reader.ReadString('\n')
	trainInput := strings.Fields(inputTrain)
	train[0], _ = strconv.Atoi(trainInput[0])
	train[1], _ = strconv.Atoi(trainInput[1])

	inputBus, _ := reader.ReadString('\n')
	busInput := strings.Fields(inputBus)
	bus[0], _ = strconv.Atoi(busInput[0])
	bus[1], _ = strconv.Atoi(busInput[1])

	fmt.Println(min(train[0], train[1]) + min(bus[0], bus[1]))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
