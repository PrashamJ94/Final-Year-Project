package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nm, _ := reader.ReadString('\n')
	nmArr := strings.Fields(nm)
	n, _ := strconv.Atoi(nmArr[0])
	m, _ := strconv.Atoi(nmArr[1])

	rc, _ := reader.ReadString('\n')
	rcArr := strings.Fields(rc)
	rcInt := make([]int, n)
	for i := range rcArr {
		rcInt[i], _ = strconv.Atoi(rcArr[i])
	}

	gc, _ := reader.ReadString('\n')
	gcArr := strings.Fields(gc)
	gcInt := make([]int, m)
	for i := range gcArr {
		gcInt[i], _ = strconv.Atoi(gcArr[i])
	}

	i, j := 0, 0
	for i < n && j < m {
		if rcInt[i] <= gcInt[j] {
			i++
		}
		j++
	}
	fmt.Println(n - i)
}

// End of Code
