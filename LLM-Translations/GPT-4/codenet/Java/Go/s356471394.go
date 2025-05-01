package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	N, M, D, num int
	room         [][]rune
)

func main() {
	scanner := bufio.NewReader(os.Stdin)

	input, _ := scanner.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(input), " ")

	N, _ = strconv.Atoi(nums[0])
	M, _ = strconv.Atoi(nums[1])
	D, _ = strconv.Atoi(nums[2])

	room = make([][]rune, N)

	for i := 0; i < N; i++ {
		input, _ := scanner.ReadString('\n')
		room[i] = []rune(strings.TrimSpace(input))
	}

	if M >= D {
		setWE()
	}

	if N >= D {
		setNS()
	}

	fmt.Println(num)

}

func setWE() {
	canPut := true

	for i := 0; i < N; i++ {
		for j := 0; j < M-D+1; j++ {
			canPut = true

			for k := 0; k < D; k++ {
				if room[i][j+k] == '#' {
					canPut = false
					break
				}
			}

			if canPut == true {
				num++
			}

		}
	}

}

func setNS() {
	canPut := true

	for i := 0; i < M; i++ {
		for j := 0; j < N-D+1; j++ {
			canPut = true

			for k := 0; k < D; k++ {
				if room[j+k][i] == '#' {
					canPut = false
					break
				}
			}

			if canPut == true {
				num++
			}

		}
	}

}

// 
