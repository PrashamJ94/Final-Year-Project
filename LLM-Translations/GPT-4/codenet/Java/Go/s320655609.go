package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Main struct {
	constraints []int64
	N           int64
	result      int64
}

func NewMain() (*Main, error) {
	main := &Main{
		constraints: make([]int64, 5),
	}
	reader := bufio.NewReader(os.Stdin)
	input, _, err := reader.ReadLine()
	if err != nil {
		return nil, err
	}
	main.N, err = strconv.ParseInt(string(input), 10, 64)
	if err != nil {
		return nil, err
	}
	for i := 0; i < 5; i++ {
		input, _, err = reader.ReadLine()
		if err != nil {
			return nil, err
		}
		constraint, err := strconv.ParseInt(string(input), 10, 64)
		if err != nil {
			return nil, err
		}
		main.constraints[i] = constraint
	}

	main.calc()
	return main, nil
}

func (m *Main) calc() {
	min := int64(^uint64(0) >> 1)
	for _, c := range m.constraints {
		if c < min {
			min = c
		}
	}
	time := m.N / min
	if m.N%min != 0 {
		time++
	}
	time += 4
	m.result = time
}

func main() {
	main, err := NewMain()
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	fmt.Println(main.result)
}

// 
