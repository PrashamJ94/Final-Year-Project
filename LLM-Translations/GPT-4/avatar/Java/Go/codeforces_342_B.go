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
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	inputArr := strings.Split(input, " ")

	m, _ := strconv.Atoi(inputArr[1])
	s, _ := strconv.Atoi(inputArr[2])
	f, _ := strconv.Atoi(inputArr[3])

	maxT := -1
	mapData := make(map[int][]int)

	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mth = strings.TrimSpace(mth)
		mthArr := strings.Split(mth, " ")

		k, _ := strconv.Atoi(mthArr[0])
		mapData[k] = []int{}
		a, _ := strconv.Atoi(mthArr[1])
		b, _ := strconv.Atoi(mthArr[2])
		mapData[k] = append(mapData[k], a)
		mapData[k] = append(mapData[k], b)

		if maxT < k {
			maxT = k
		}

		m--
	}

	var actions strings.Builder
	var M byte
	if s < f {
		M = 'R'
	} else {
		M = 'L'
	}

	d := 1
	if s >= f {
		d = -1
	}

	cur := s
	a, b := -1, -1

	for t := 1; t <= maxT; t++ {
		if data, ok := mapData[t]; ok {
			a, b = data[0], data[1]
		}

		if _, ok := mapData[t]; ok && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteByte('X')
		} else {
			actions.WriteByte(M)
			cur += d
		}

		if cur == f {
			break
		}
	}

	for cur != f {
		actions.WriteByte(M)
		cur += d
	}

	fmt.Println(actions.String())
}

// //End of Code.
