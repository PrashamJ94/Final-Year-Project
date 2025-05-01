
package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {

	var N, L int

	fmt.Scan(&N)
	fmt.Scan(&L)

	v := make([]string, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&v[i])
	}

	sort.Strings(v)

	var result strings.Builder
	for i := 0; i < len(v); i++ {
		result.WriteString(v[i])
	}
	fmt.Println(result.String())
}
// 


