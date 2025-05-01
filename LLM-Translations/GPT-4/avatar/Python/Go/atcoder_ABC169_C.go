package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	s := sc.Text()
	nums := strings.Split(s, " ")
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.ParseFloat(nums[1], 64)
	b100 := int(b * 100 + 0.1)
	fmt.Println(a * b100 / 100)
}
// End of Code

Please note that Go doesn't support lambda functions and doesn't have an equivalent for Python's map function, so some parts of the original Python code cannot be directly translated to Go.
