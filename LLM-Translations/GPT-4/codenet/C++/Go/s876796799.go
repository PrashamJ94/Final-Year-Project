package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int64, N)
	ind_a := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i
	}

	used_inds := make([]int, 0)
	var ans int64 = 0

	for i := 0; i < N; i++ {
		var left_border int64
		var right_border int64
		
		cur_ind := ind_a[i]
		left_it := sort.Search(len(used_inds), func(j int) bool { return used_inds[j] >= cur_ind })
		right_it := sort.Search(len(used_inds), func(j int) bool { return used_inds[j] >= cur_ind + 1 })

		if left_it == 0 {
			left_border = -1
		} else {
			if left_it == len(used_inds) || used_inds[left_it] > cur_ind {
				left_it--
			}
			left_border = int64(used_inds[left_it])
		}
		if right_it == len(used_inds) {
			right_border = int64(N)
		} else {
			right_border = int64(used_inds[right_it])
		}
		ans += (int64(cur_ind) - left_border) * (right_border - int64(cur_ind)) * (int64(i) + 1)

		used_inds = append(used_inds[:left_it], append([]int{cur_ind}, used_inds[left_it:]...)...)
	}

	fmt.Println(ans)
}

// 
