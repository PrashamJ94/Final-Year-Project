package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

func main() {
	t := make([][]string, 0)
	sc := bufio.NewScanner(os.Stdin)
	for i := 0; i < 4; i++ {
		sc.Scan()
		l := strings.Split(sc.Text(), "")
		t = append(t, l)
	}
	black, white, correct := 0, 0, 0
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if t[i][j] == "#" {
				black++
			} else {
				white++
			}
			if t[i][j+1] == "#" {
				black++
			} else {
				white++
			}
			if t[i+1][j] == "#" {
				black++
			} else {
				white++
			}
			if t[i+1][j+1] == "#" {
				black++
			} else {
				white++
			}
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = 1
				break
			}
			black, white = 0, 0
		}
	}
	if correct == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
} // End of Code
