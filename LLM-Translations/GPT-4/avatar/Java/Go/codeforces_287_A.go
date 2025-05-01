package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var str [4]string
	for i := 0; i < 4; i++ {
		scanner.Scan()
		str[i] = scanner.Text()
	}

	yes := 0
	for u := 0; u < 3; u++ {
		for i := 0; i < 3; i++ {
			if ((str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) ||
				(str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i]))) {
				yes = 1
				fmt.Println("YES")
				break
			}
		}
		if yes == 1 {
			break
		}
	}
	if yes == 0 {
		fmt.Println("NO")
	}
}

// //End of Code
