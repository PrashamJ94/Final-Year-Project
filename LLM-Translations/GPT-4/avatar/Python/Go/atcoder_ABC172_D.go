package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	ans := 0
	for i := 1; i <= N; i++ {
		ans += i * (N / i) * (N / i + 1) / 2
	}
	fmt.Println(ans)
}
// End of Code


