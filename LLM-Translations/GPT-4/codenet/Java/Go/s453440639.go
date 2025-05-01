package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)

	var H, W int
	fmt.Scanf("%d %d\n", &H, &W)

	S := make([]string, H)

	for i := 0; i < H; i++ {
		S[i], _ = scanner.ReadString('\n')
		S[i] = strings.TrimSpace(S[i])
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if S[i][j] == '.' {
				count := 0
				for a := -1; a <= 1; a++ {
					if i + a < 0 || H <= i + a {
						continue
					}
					for b := -1; b <= 1; b++ {
						if j + b < 0 || W <= j + b {
							continue
						}
						if S[i + a][j + b] == '#' {
							count++
						}
					}
				}
				S[i] = S[i][:j] + string(count+48) + S[i][j+1:]
			}
			fmt.Printf("%c", S[i][j])
		}
		fmt.Printf("\n")
	}
}
// 
