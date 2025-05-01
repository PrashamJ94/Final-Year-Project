package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}
	fmt.Println(solve(arr))
}

func solve(arr []int) int {
	n := len(arr)
	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted)
	total := int64(n) * int64(n+1) / 2
	l, r := 0, n-1
	for l < r {
		mid := l + (r-l)/2
		target := sorted[mid]
		cur := 0
		cnt := int64(0)
		bit := make([]int64, 2*n+2)
		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++
		}
		for i := 0; i < n; i++ {
			if arr[i] <= target {
				cur++
			} else {
				cur--
			}
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++
			}
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x]
			}
		}
		if cnt >= total/2+1 {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return sorted[l]
}

// //End of Code
