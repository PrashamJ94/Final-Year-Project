package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	s := scanner.Text()

	scanner.Scan()
	k, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	var sb string
	for i := 0; i < len(s); i++ {
		if (26-(s[i]-'a')) <= byte(k) && s[i] != 'a' {
			k -= int64(26 - (s[i] - 'a'))
			sb += "a"
		} else {
			sb += string(s[i])
		}
	}
	if k > 0 {
		t := sb[len(sb)-1]
		sb = sb[:len(sb)-1]
		sb += string('a' + (t-'a'+byte(k))%26)
	}
	fmt.Println(sb)
}

// 
