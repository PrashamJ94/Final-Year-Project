
package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var ans int
	if n > k {
		tmp := n % k
		if tmp >= k-tmp {
			ans = k - tmp
		} else {
			ans = tmp
		}
	} else if n < k {
		if n >= k-n {
			ans = k - n
		} else {
			ans = n
		}
	} else {
		ans = 0
	}

	fmt.Println(ans)
}
// 



