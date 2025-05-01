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
	writer := bufio.NewWriter(os.Stdout)

	line, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(line))

	line, _ := reader.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(line), " ")

	hm := make(map[int]int)
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(nums[i])
		hm[val] = hm[val] + 1
	}

	ans := 0
	for val, num := range hm {
		if num > val {
			ans += num - val
		} else if num < val {
			ans += num
		}
	}

	fmt.Println(ans)
	writer.Flush()
}
// 
