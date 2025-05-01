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
	scanner.Split(bufio.ScanWords)

	N := nextInt(scanner)
	K := nextInt(scanner)
	S := nextString(scanner)

	firstTime := true
	step := 1

	for K > 0 {
		var T strings.Builder
		T.WriteString(S)
		reverse(&T)

		var revU strings.Builder
		revU.WriteString(S)
		revU.WriteString(T.String())
		reverse(&revU)

		sDash := S
		for i := N; i >= 0; i -= step {
			tmp := revU.String()[i : i+N]
			if sDash > tmp {
				sDash = tmp
			} else {
				if !firstTime {
					break
				}
			}
		}

		if firstTime {
			firstTime = false
			if float64(1<<K) > float64(N) {
				c := sDash[0]
				for i := 0; i < N; i++ {
					fmt.Printf("%c", c)
				}
				fmt.Println()
				os.Exit(0)
			}
		} else {
			step += step
		}

		K--
		S = reverseStr(sDash)
	}

	fmt.Println(reverseStr(S))
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func reverse(sb *strings.Builder) {
	str := sb.String()
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	sb.Reset()
	sb.WriteString(string(runes))
}

func reverseStr(str string) string {
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// //End of Code
