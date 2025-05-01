package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 200 + 10

var f [N]int
var b [N]byte

func getFail(b []byte, m int) {
	j := 0
	f[0], f[1] = 0, 0
	for i := 2; i <= m; i++ {
		for j > 0 && b[j+1] != b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	s1 := scanner.Text()

	scanner.Scan()
	str := scanner.Text()

	cnt := 0
	for i := 0; i < n; i++ {
		cnt++
		b[cnt] = str[i]
	}
	for i := 0; i < n; i++ {
		cnt++
		b[cnt] = s1[i]
	}
	getFail(b[:], cnt)

	len := f[cnt]
	if n < len {
		len = n
	}
	if n < len {
		len = n
	}
	fmt.Println(2*n - len)
}

// //End of Code.
