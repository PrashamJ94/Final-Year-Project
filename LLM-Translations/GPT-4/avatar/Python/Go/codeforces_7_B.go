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
	tm := strings.Split(scanner.Text(), " ")
	t, _ := strconv.Atoi(tm[0])
	m, _ := strconv.Atoi(tm[1])
	alocuente := make([]int, m)
	ind := 1
	for i := 0; i < t; i++ {
		scanner.Scan()
		op := strings.Split(scanner.Text(), " ")
		if op[0] == "alloc" {
			pos := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos++
					if pos == toInt(op[1]) {
						for k := j - toInt(op[1]) + 1; k <= j; k++ {
							alocuente[k] = ind
						}
						fmt.Println(ind)
						ind++
						break
					}
				} else {
					pos = 0
				}
			}
			if pos != toInt(op[1]) {
				fmt.Println("NULL")
			}
		} else if op[0] == "erase" {
			pos := 0
			if !contains(alocuente, toInt(op[1])) || toInt(op[1]) == 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j := 0; j < m; j++ {
					if alocuente[j] == toInt(op[1]) {
						alocuente[j] = 0
					}
				}
			}
		} else if op[0] == "defragment" {
			nonZero, zero := divideByZero(alocuente)
			alocuente = append(nonZero, zero...)
		}
	}
}

func toInt(s string) int {
	res, _ := strconv.Atoi(s)
	return res
}

func contains(arr []int, num int) bool {
	for _, a := range arr {
		if a == num {
			return true
		}
	}
	return false
}

func divideByZero(arr []int) ([]int, []int) {
	nonZero := []int{}
	zero := []int{}
	for _, a := range arr {
		if a == 0 {
			zero = append(zero, a)
		} else {
			nonZero = append(nonZero, a)
		}
	}
	return nonZero, zero
}

// End of Code
