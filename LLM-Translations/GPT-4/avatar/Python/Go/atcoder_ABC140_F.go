package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	S := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(S)))

	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

	cur := make([]int, 0)
	cur = append(cur, S[0])
	flag[0] = false

	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)

		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				cur = append(cur, S[k])
				j++
				flag[k] = false

				if j == jM {
					break
				}
			} else {
				fmt.Println("No")
				return
			}
		}
		sort.Sort(sort.Reverse(sort.IntSlice(cur)))
	}
	fmt.Println("Yes")
}
// End of Code


Please note that Go uses different libraries and methods for handling inputs, sorting arrays, and other operations, so some changes have been made to accommodate these differences. For example, the `fmt.Scan` function is used to read inputs, and `sort.Sort` is used to sort arrays. Also, Go doesn't support list comprehension or slicing in the same way as Python, so some adjustments have been made in those areas as well.
