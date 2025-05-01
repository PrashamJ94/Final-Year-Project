package main

import (
	"fmt"
)

func main() {

	var N int
	fmt.Scanf("%d", &N)

	var sum int64 = 0
	var wa int64 = 0
	A := make([]int, N)
	sa := make([]int, N)
	var ans bool
	var shou int64
	var min int64 = 1123456789

	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
		sum += int64(A[i])
		wa += int64(i + 1)
	}

	if sum%wa != 0 {
		ans = false
	} else {
		shou = sum / wa
		for i := 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - int(shou)
		}

		ans = true
		for i := 0; i < N-1; i++ {
			if sa[i] <= 0 && sa[i]%N == 0 {
				ans = true
			} else {
				ans = false
				break
			}
		}
	}

	if ans {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

}
// 
