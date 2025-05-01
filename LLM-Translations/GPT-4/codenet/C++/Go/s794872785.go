
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	solve()
}

func solve() {
	var maxsize int
	var maxcnt int
	var ansNum int
	var ansNum2 int
	var strV []string

	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		in := scanner.Text()
		strV = append(strV, in)
		if maxsize < len(in) {
			maxsize = len(in)
			ansNum = len(strV) - 1
		}
	}

	for i := 0; i < len(strV); i++ {
		cnt := 0
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] {
				cnt++
			}
		}
		if maxcnt < cnt {
			maxcnt = cnt
			ansNum2 = i
		}
	}

	fmt.Println(strV[ansNum2], strV[ansNum])
}
// 


