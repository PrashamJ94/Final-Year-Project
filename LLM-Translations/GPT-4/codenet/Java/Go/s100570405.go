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
	Sd := scanner.Text()
	scanner.Scan()
	T := scanner.Text()

	count := 0
	ok := false
	first := -1
	end := -1

	for j := 0; j < len(Sd); j++ {
		count = 0
		for i := 0; i+j < len(Sd); i++ {
			c := Sd[i+j]
			if c == '?' || c == T[count] {
				count++
				if count == len(T) {
					first = i + j - len(T) + 1
					end = i + j
					ok = true
					break
				}
			} else {
				count = 0
			}
		}
	}

	if ok {
		for i := 0; i < len(Sd); i++ {
			if first <= i && i <= end {
				fmt.Print(string(T[i-first]))
			} else {
				if Sd[i] == '?' {
					fmt.Print("a")
				} else {
					fmt.Print(string(Sd[i]))
				}
			}
		}
		fmt.Println()
	} else {
		fmt.Println("UNRESTORABLE")
	}
}

type MyInput struct {
	scanner *bufio.Scanner
}

func (mi *MyInput) hasNext() bool {
	return mi.scanner.Scan()
}

func (mi *MyInput) next() string {
	return mi.scanner.Text()
}

func (mi *MyInput) nextInt() int {
	n, _ := strconv.Atoi(mi.next())
	return n
}

func (mi *MyInput) nextLong() int64 {
	n, _ := strconv.ParseInt(mi.next(), 10, 64)
	return n
}

func (mi *MyInput) nextDouble() float64 {
	n, _ := strconv.ParseFloat(mi.next(), 64)
	return n
}

func isPrintableChar(c byte) bool {
	return 33 <= c && c <= 126
}

func newMyInput(scanner *bufio.Scanner) *MyInput {
	mi := new(MyInput)
	mi.scanner = scanner
	return mi
}

func readStringSlice() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	return strings.Split(line, " ")
}

func readIntSlice() []int {
	strs := readStringSlice()
	ints := make([]int, len(strs))
	for i, s := range strs {
		ints[i], _ = strconv.Atoi(s)
	}
	return ints
}

func readLongSlice() []int64 {
	strs := readStringSlice()
	longs := make([]int64, len(strs))
	for i, s := range strs {
		longs[i], _ = strconv.ParseInt(s, 10, 64)
	}
	return longs
}

func readDoubleSlice() []float64 {
	strs := readStringSlice()
	doubles := make([]float64, len(strs))
	for i, s := range strs {
		doubles[i], _ = strconv.ParseFloat(s, 64)
	}
	return doubles
}

// 
