package main

import (
	"fmt"
	"strings"
)

func solve(S_d, T string) {
	end := len(S_d) - 1
	first := end - len(T) + 1

	for first >= 0 {
		t_i := 0
		for s_i := first; s_i <= end; s_i++ {
			if T[t_i] != S_d[s_i] && S_d[s_i] != '?' {
				break
			}
			t_i++
		}

		if t_i == len(T) {
			break
		}

		first--
		end--
	}

	if first < 0 {
		fmt.Println("UNRESTORABLE")
		return
	}

	ans := []byte(S_d)
	t_i := 0
	for i := first; i <= end; i++ {
		ans[i] = T[t_i]
		t_i++
	}

	ansStr := strings.ReplaceAll(string(ans), "?", "a")
	fmt.Println(ansStr)
}

func main() {
	S_d := "??p??d?"
	T := "abc"
	solve(S_d, T)
}
// 
