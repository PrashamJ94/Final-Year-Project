
package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	queries := make([][]int, t)
	for i := 0; i < t; i++ {
		scanner.Scan()
		queryStr := strings.Split(scanner.Text(), " ")
		for j := 0; j < len(queryStr); j++ {
			queryInt, _ := strconv.Atoi(queryStr[j])
			queries[i] = append(queries[i], queryInt)
		}
	}

	res := make([]string, t)
	for i, query := range queries {
		k := query[0] / query[1]
		if k*query[2] >= query[0] {
			res[i] = "Yes"
		} else {
			res[i] = "No"
		}
	}

	fmt.Println(strings.Join(res, "\n"))
}

// End of Code

