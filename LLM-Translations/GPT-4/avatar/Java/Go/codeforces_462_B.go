package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type c462b struct {
	left int
}

type c462bSlice []*c462b

func (c c462bSlice) Len() int {
	return len(c)
}

func (c c462bSlice) Less(i, j int) bool {
	return c[i].left < c[j].left
}

func (c c462bSlice) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	text, _ := reader.ReadString('\n')
	input := strings.Split(strings.TrimSpace(text), " ")

	n, _ := strconv.Atoi(input[0])
	k, _ := strconv.Atoi(input[1])

	cards := make(c462bSlice, 26)
	for i := range cards {
		cards[i] = &c462b{left: 0}
	}

	text, _ = reader.ReadString('\n')
	s := strings.TrimSpace(text)

	for t := 0; t < n; t++ {
		cards[s[t]-'A'].left++
	}

	var ans int64 = 0
	for i := 0; i < k; {
		sort.Sort(sort.Reverse(cards))
		change := min(cards[0].left, k-i)
		ans += int64(change * change)
		cards[0].left -= change
		i += change
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// //End of Code.
