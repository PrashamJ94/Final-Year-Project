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
	input := scanner.Text()
	inputs := strings.Split(input, " ")
	n, _ := strconv.Atoi(inputs[0])
	s, _ := strconv.Atoi(inputs[1])

	max := 0

	for n > 0 {
		scanner.Scan()
		input = scanner.Text()
		inputs = strings.Split(input, " ")
		f, _ := strconv.Atoi(inputs[0])
		t, _ := strconv.Atoi(inputs[1])

		if max < f+t {
			max = f + t
		}

		n--
	}

	fmt.Println(max)

	if max < s {
		fmt.Println(s)
	} else {
		fmt.Println(max)
	}
}

// //End of Code.
