
package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func allSame(arr []int) bool {
	for _, v := range arr {
		if v != arr[0] {
			return false
		}
	}
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	nk, _ := reader.ReadString('\n')
	nkArr := strings.Fields(nk)
	n, _ := strconv.Atoi(nkArr[0])
	k, _ := strconv.Atoi(nkArr[1])

	elemsInput, _ := reader.ReadString('\n')
	elemsArr := strings.Fields(elemsInput)
	elems := make([]int, n)
	for i, v := range elemsArr {
		elems[i], _ = strconv.Atoi(v)
	}

	if allSame(elems) {
		fmt.Println(0)
		return
	}
	if k == 1 {
		fmt.Println(-1)
		return
	}
	if !allSame(elems[k-1:]) {
		fmt.Println(-1)
		return
	}
	target := elems[n-1]
	toDelete := elems[0 : k-1]
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}
	fmt.Println(len(toDelete))
}

// End of Code


