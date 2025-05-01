package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
	var K int
	var S string

	fmt.Scan(&K)
	
	reader := bufio.NewReader(os.Stdin)
	S, _ = reader.ReadString('\n')

	if len(S) <= K {
		fmt.Println(S)
	} else {
		fmt.Println(S[:K] + "...")
	}
}

// End of Code
