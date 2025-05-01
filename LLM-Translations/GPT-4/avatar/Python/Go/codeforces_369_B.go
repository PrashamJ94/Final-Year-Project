
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func getNums(num int, t int) []int {
	result := make([]int, num)
	for i := 0; i < num; i++ {
		if i < t%num {
			result[i] = t/num + 1
		} else {
			result[i] = t / num
		}
	}
	return result
}

func main() {
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)

	ans := append(getNums(k, sk), getNums(n-k, sa-sk)...)

	strAns := make([]string, len(ans))
	for i, num := range ans {
		strAns[i] = strconv.Itoa(num)
	}

	fmt.Println(strings.Join(strAns, " "))
}
// End of Code

In the Go code above, we implemented the `getNums` function that does the same job as the Python version. In the `main` function, we read the input using `fmt.Scan`. The `getNums` function is then called for `k` and `sk`, and `n-k` and `sa-sk`. The results are combined using the `append` function. Finally, the numbers in `ans` are converted to strings and printed as a space-separated string.
