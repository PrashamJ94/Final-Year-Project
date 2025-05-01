
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var reader = bufio.NewReader(os.Stdin)

func readInt() (int, error) {
	s, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	s = strings.TrimSpace(s)
	return strconv.Atoi(s)
}

func main() {
	ans, err := solve()
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
	fmt.Println(ans)
}

func solve() (int, error) {
	K, err := readInt()
	if err != nil {
		return 0, err
	}
	if K%2 == 0 || K%5 == 0 {
		return -1, nil
	}
	if K%7 == 0 {
		K /= 7
	}
	K *= 9
	ans := 1
	remainder := 10 % K
	for remainder != 1 {
		ans++
		remainder = remainder * 10 % K
	}
	return ans, nil
}

//End of Code.
