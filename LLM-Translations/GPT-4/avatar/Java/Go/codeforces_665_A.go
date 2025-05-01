package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	aTokens := readTokens(reader)
	a, _ := strconv.Atoi(aTokens[0])
	tA, _ := strconv.Atoi(aTokens[1])

	bTokens := readTokens(reader)
	b, _ := strconv.Atoi(bTokens[0])
	tB, _ := strconv.Atoi(bTokens[1])

	timing, _ := reader.ReadString('\n')
	timing = strings.TrimSpace(timing)
	hrs, _ := strconv.Atoi(timing[:2])
	mins, _ := strconv.Atoi(timing[3:])

	simDeparture := hrs*60 + mins
	simArrival := simDeparture + tA
	counter := 0

	for i := 300; i < 1440; i += b {
		busDeparture := i
		busArrival := i + tB

		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}
		counter++
	}

	fmt.Fprintln(writer, counter)
}

func readTokens(reader *bufio.Reader) []string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return strings.Split(line, " ")
}

// //End of Code
