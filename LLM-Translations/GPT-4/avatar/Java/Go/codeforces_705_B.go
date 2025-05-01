
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) next() string {
	word, _ := fr.br.ReadString(' ')
	return strings.TrimSpace(word)
}

func (fr *FastReader) nextInt() int {
	n, _ := strconv.Atoi(fr.next())
	return n
}

func (fr *FastReader) nextLong() int64 {
	n, _ := strconv.ParseInt(fr.next(), 10, 64)
	return n
}

func (fr *FastReader) nextDouble() float64 {
	n, _ := strconv.ParseFloat(fr.next(), 64)
	return n
}

func (fr *FastReader) nextLine() string {
	line, _ := fr.br.ReadString('\n')
	return strings.TrimSpace(line)
}

func main() {
	fr := NewFastReader()
	t := 1
	for t > 0 {
		solve(fr)
		t--
	}
}

func solve(fr *FastReader) {
	t := fr.nextInt()
	arr := make([]int, t)
	for i := 0; i < len(arr); i++ {
		arr[i] = fr.nextInt()
	}
	prevWinner := 0
	for i := 0; i < len(arr); i++ {
		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}
		}
		if prevWinner == 2 || prevWinner == 0 {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(2)
				prevWinner = 2
			} else {
				fmt.Println(1)
				prevWinner = 1
			}
		} else {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(1)
				prevWinner = 1
			} else {
				fmt.Println(2)
				prevWinner = 2
			}
		}
	}
}

// //End of Code


