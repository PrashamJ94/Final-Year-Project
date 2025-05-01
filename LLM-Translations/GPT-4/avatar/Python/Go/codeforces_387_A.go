package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var h1, m1, h2, m2 int
	h1, m1 = getHourMinute() 
	m1 += h1 * 60
	h2, m2 = getHourMinute()
	m2 += h2 * 60
	m2 = m1 - m2
	m2 %= 1440
	fmt.Printf("%02d:%02d", m2 / 60, m2 % 60)
}

func getHourMinute() (int, int) {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, ":")
	hour, _ := strconv.Atoi(parts[0])
	minute, _ := strconv.Atoi(parts[1])
	return hour, minute
}

// End of Code
