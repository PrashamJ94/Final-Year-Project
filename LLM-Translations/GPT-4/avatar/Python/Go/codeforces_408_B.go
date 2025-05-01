package main
import (
	"fmt"
	"strings"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var line string
	fmt.Scan(&line)

	boughtCount := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		boughtCount[color]++
	}

	fmt.Scan(&line)

	madeCount := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		madeCount[color]++
	}

	res := 0
	for color, count := range madeCount {
		if boughtCount[color] == 0 {
			fmt.Println(-1)
			return
		}
		res += min(boughtCount[color], count)
	}

	fmt.Println(res)
}

End of Code.
