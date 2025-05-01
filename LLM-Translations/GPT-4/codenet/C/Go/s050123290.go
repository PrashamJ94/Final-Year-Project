
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const N = 1000

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanBytes)
	var su [N]byte
	var susum int
	var j int

	for {
		for j = 0; j <= N; j++ {
			scanner.Scan()
			su[j] = scanner.Bytes()[0]
			if su[j] == '\n' {
				break
			}
			num, _ := strconv.Atoi(string(su[j]))
			susum += num
		}
		if su[0] == '0' {
			break
		}
		fmt.Println(susum)
		susum = 0
	}
}
// 

