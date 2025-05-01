package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	split := strings.Split(scanner.Text(), " ")

	n, _ := strconv.Atoi(split[0])
	k, _ := strconv.Atoi(split[1])

	scanner.Scan()
	nums := strings.Split(scanner.Text(), " ")

	ints := make([]int, n)

	for i := 0; i < n; i++ {
		ints[i], _ = strconv.Atoi(nums[i])
	}

	sort.Ints(ints)

	sum := 0
	for i := 0; i < k; i++ {
		sum += ints[i]
	}

	fmt.Println(sum)
}
// End of Code
