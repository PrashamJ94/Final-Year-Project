
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := range A {
		fmt.Scan(&A[i])
	}

	mn, mx := N+1, -1
	for i := 0; i < N; i++ {
		if i+1 != A[i] {
			if i < mn {
				mn = i
			}
			if i > mx {
				mx = i
			}
		}
	}

	if mx == -1 {
		fmt.Println("0 0")
	} else {
		temp := append(A[:mn], A[mn:mx+1]...)
		sort.Slice(temp, func(i, j int) bool {
			return temp[i] > temp[j]
		})
		A = append(temp, A[mx+1:]...)

		B := make([]int, len(A))
		copy(B, A)
		sort.Ints(B)

		if equal(A, B) {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
		}
	}
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}
// End of Code

In the Go version of your code, I've introduced a helper function `equal` to compare two slices. The Go standard library doesn't provide a built-in way to do this.
