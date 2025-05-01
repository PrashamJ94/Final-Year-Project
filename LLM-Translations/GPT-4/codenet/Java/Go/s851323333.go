package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)
	list := []int{}
	for {
		line, _, _ := scanner.ReadLine()
		if line == nil {
			break
		}
		num, _ := strconv.Atoi(strings.TrimSpace(string(line)))
		if num == 0 {
			fmt.Println(list[len(list)-1])
			list = list[:len(list)-1]
		} else {
			list = append(list, num)
		}
	}
}
// 
