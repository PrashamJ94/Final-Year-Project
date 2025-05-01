package main

import (
	"fmt"
	"strconv"
	"os"
	"bufio"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	ryuka := make([]int64, n+1)
	ryuka[0] = 2
	ryuka[1] = 1
	for i := 2; i < n+1; i++ {
		ryuka[i] = ryuka[i-1] + ryuka[i-2]
	}
	fmt.Println(ryuka[n])
}
// 
