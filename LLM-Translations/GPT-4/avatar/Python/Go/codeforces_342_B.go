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

	nmsf, _ := reader.ReadString('\n')
	nmsf = strings.Trim(nmsf, "\n")
	nmsfSplitted := strings.Split(nmsf, " ")

	n, _ := strconv.Atoi(nmsfSplitted[0])
	m, _ := strconv.Atoi(nmsfSplitted[1])
	s, _ := strconv.Atoi(nmsfSplitted[2])
	f, _ := strconv.Atoi(nmsfSplitted[3])

	var d int
	var c string
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}

	res := ""
	i := 1
	j := s

	tlr, _ := reader.ReadString('\n')
	tlr = strings.Trim(tlr, "\n")
	tlrSplitted := strings.Split(tlr, " ")

	t, _ := strconv.Atoi(tlrSplitted[0])
	l, _ := strconv.Atoi(tlrSplitted[1])
	r, _ := strconv.Atoi(tlrSplitted[2])

	k := 1
	for j != f {
		if i > t && k < m {
			tlr, _ := reader.ReadString('\n')
			tlr = strings.Trim(tlr, "\n")
			tlrSplitted := strings.Split(tlr, " ")

			t, _ = strconv.Atoi(tlrSplitted[0])
			l, _ = strconv.Atoi(tlrSplitted[1])
			r, _ = strconv.Atoi(tlrSplitted[2])

			k++
		}
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"
		} else {
			res += c
			j += d
		}
		i++
	}
	fmt.Println(res)
}

// End of Code
