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
	sc, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(sc))
	str := make([]string, n)
	for i := 0; i < n; i++ {
		str[i], _ = reader.ReadString('\n')
		str[i] = strings.TrimSpace(str[i])
	}
	mark := []string{"S", "H", "C", "D"}
	for _, ma := range mark {
		for i := 1; i <= 13; i++ {
			s := strconv.Itoa(i)
			st := ma + " " + s
			if contains(str, st) {
				continue
			} else {
				fmt.Println(st)
			}
		}
	}
}

func contains(arr []string, str string) bool {
	for _, a := range arr {
		if a == str {
			return true
		}
	}
	return false
}

// 
